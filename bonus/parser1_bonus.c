/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 00:27:28 by derrick           #+#    #+#             */
/*   Updated: 2021/03/31 01:21:26 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		special_atoi(char **str)
{
	int				sign;
	long long int	res;
	long long int	res_tmp;
	int				changed;

	changed = 0;
	res = 0;
	while (**str && ft_isspace(**str))
		(*str)++;
	sign = (**str == '-') ? -1 : 1;
	if (**str == '+' || **str == '-')
		(*str)++;
	while (**str && ft_isdigit(**str))
	{
		changed++;
		res_tmp = res;
		res = res * 10 + (**str - '0') * sign;
		if ((res < res_tmp && sign == 1) || (res > res_tmp && sign == -1))
			return (sign == 1 ? -1 : 0);
		(*str)++;
	}
	res = (changed > 9 || !changed) ? -1 : res;
	return ((int)res);
}

void	parse_res(int fd, t_cube3d *a)
{
	char *temp;
	char *to_free;

	if (a->prs.res_x || a->prs.res_y)
		exit_all(a, "Double Res\n");
	a->prs.flag++;
	if (get_next_line(fd, &temp) < 0)
		exit_all(a, "Something with resolution ooor again gnl\n");
	to_free = temp;
	check_letters(temp, a, ' ');
	a->prs.res_x = special_atoi(&temp);
	a->prs.res_y = special_atoi(&temp);
	check_letters(temp, a, 'X');
	free(to_free);
	if (a->prs.res_x > RESX_MAX && !a->map.screenshot)
		a->prs.res_x = RESX_MAX;
	if (a->prs.res_y > RESY_MAX && !a->map.screenshot)
		a->prs.res_y = RESY_MAX;
	if (a->prs.res_x < RESX_MIN)
		a->prs.res_x = RESX_MIN;
	if (a->prs.res_y < RESY_MIN)
		a->prs.res_y = RESY_MIN;
}

void	read_path(int fd, char *path, t_cube3d *a)
{
	char	temp;
	int		i;

	i = 0;
	if (path[0])
		exit_all(a, "Double paths in file\n");
	while (read(fd, &temp, 1))
	{
		while (ft_isspace(temp) && temp != '\n')
			read(fd, &temp, 1);
		if (temp == '\n')
			break ;
		path[i++] = temp;
	}
	path[i] = (path[0]) ? 0 : 1;
	path[i + 1] = (path[0]) ? 0 : 1;
}

void	parse_ceil_color(int fd, t_cube3d *a)
{
	char	*temp;
	char	*to_free;
	int		i;

	i = -1;
	if (get_next_line(fd, &temp) < 0)
		exit_all(a, "Hard fail in color parcer provided by gnl\n");
	to_free = temp;
	check_letters(temp, a, ',');
	while (++i < 3)
	{
		if (i == 0)
			a->prs.c_r = special_atoi(&temp);
		else if (i == 1)
			a->prs.c_g = special_atoi(&temp);
		else if (i == 2)
			a->prs.c_b = special_atoi(&temp);
		while (ft_isspace(*temp))
			temp++;
		if (*(temp++) == ',')
			while (ft_isspace(*temp))
				temp++;
	}
	check_letters(temp - 1, a, 'X');
	free(to_free);
}

void	parse_floor_color(int fd, t_cube3d *a)
{
	char	*temp;
	char	*to_free;
	int		i;

	i = -1;
	if (get_next_line(fd, &temp) < 0)
		exit_all(a, "Hard fail in color parcer provided by gnl\n");
	to_free = temp;
	check_letters(temp, a, ',');
	while (++i < 3)
	{
		if (i == 0)
			a->prs.f_r = special_atoi(&temp);
		else if (i == 1)
			a->prs.f_g = special_atoi(&temp);
		else if (i == 2)
			a->prs.f_b = special_atoi(&temp);
		while (ft_isspace(*temp))
			temp++;
		if (*(temp++) == ',')
			while (ft_isspace(*temp))
				temp++;
	}
	check_letters(temp - 1, a, 'X');
	free(to_free);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 00:27:39 by derrick           #+#    #+#             */
/*   Updated: 2021/03/31 01:42:31 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	parse_path(int fd, t_cube3d *a, char line)
{
	char temp;

	read(fd, &temp, 1);
	a->prs.flag++;
	if (line == 'N' && temp == 'O')
		read_path(fd, a->prs.n_file, a);
	else if (line == 'W' && temp == 'E')
		read_path(fd, a->prs.w_file, a);
	else if (line == 'E' && temp == 'A')
		read_path(fd, a->prs.e_file, a);
	else if (line == 'S' && temp == ' ')
		read_path(fd, a->prs.spr_file, a);
	else if (line == 'S' && temp == 'O')
		read_path(fd, a->prs.s_file, a);
	else
		exit_all(a, "Wrong path letters\n");
}

void	parse_all(int fd, t_cube3d *a)
{
	char	line;

	while (read(fd, &line, 1))
	{
		if (line == '\n')
			continue;
		else
			check_flags(fd, a, line);
		if (a->prs.flag >= 8)
			break ;
	}
	if (a->prs.flag != 8)
		exit_all(a, "Wrong number of args\n");
	mapparser(fd, a);
	if (!(a->map.map = ft_split(a->map.map1d, '\n')))
		exit_all(a, "Split failed bad\n");
	player_pos(a);
	if (a->map.col < 3 || a->map.row < 3)
		exit_all(a, "Map too small\n");
	if (!(a->map.dir == 'N' || a->map.dir == 'W' ||
		a->map.dir == 'E' || a->map.dir == 'S'))
		exit_all(a, "Wrong direction letter\n");
}

void	create_map_tocheck(t_cube3d *a)
{
	int i;
	int len;
	int c;

	i = -1;
	c = 0;
	len = protected_strlen(a->map.map[0]);
	while (a->map.map[++i])
		if (protected_strlen(a->map.map[i]) > len)
			len = protected_strlen(a->map.map[i]);
	i = -1;
	while (a->map.map[++i])
	{
		if (protected_strlen(a->map.map[i]) < len)
		{
			c = len - protected_strlen(a->map.map[i]);
			if (!(a->map.map[i] = addline(a->map.map[i], c)))
				exit_all(a, "Fail in map add\n");
		}
	}
	i = -1;
}

void	place_sprites_hexcolors(t_cube3d *a)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	a->prs.f_color = rbg_hex(a, a->prs.f_r, a->prs.f_g, a->prs.f_b);
	a->prs.c_color = rbg_hex(a, a->prs.c_r, a->prs.c_g, a->prs.c_b);
	while (a->map.map[++i])
	{
		j = -1;
		while (a->map.map[i][++j] != '\0')
		{
			if (a->map.map[(int)i][(int)j] == '2')
			{
				a->sup.x[k] = j + 0.5;
				a->sup.y[k] = i + 0.5;
				k++;
			}
		}
	}
}

void	check_flags(int fd, t_cube3d *a, char line)
{
	if (line == 'N' || line == 'W' || line == 'E')
		parse_path(fd, a, line);
	else if (line == 'R')
		parse_res(fd, a);
	else if (line == 'F')
	{
		parse_floor_color(fd, a);
		a->prs.flag++;
	}
	else if (line == 'C')
	{
		parse_ceil_color(fd, a);
		a->prs.flag++;
	}
	else if (line == 'S')
		parse_path(fd, a, line);
	else if (!ft_isspace(line))
		exit_all(a, "Wrong data letters\n");
}

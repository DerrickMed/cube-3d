/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 00:26:27 by derrick           #+#    #+#             */
/*   Updated: 2021/03/31 01:43:03 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mapparser(int fd, t_cube3d *a)
{
	char	*line;
	int		i;

	i = get_next_line(fd, &line);
	while (i && (line[0] == '\n'))
	{
		free(line);
		i = get_next_line(fd, &line);
		if (i < 0)
			exit_all(a, "Gnl error in mapparser\n");
	}
	a->map.map1d = ft_strjoin("              \n", line);
	free(line);
	while (get_next_line(fd, &line))
	{
		a->map.map1d = gnl_strjoin(a->map.map1d, line);
		ft_free(line);
	}
	a->map.map1d = gnl_strjoin(a->map.map1d, line);
	a->map.map1d = gnl_strjoin(a->map.map1d, "\n       \0");
	ft_free(line);
}

void	check_letters(char *temp, t_cube3d *a, char skip)
{
	if (skip == 'X')
	{
		while (*(temp++) != '\n' && *(temp - 1))
			if (!ft_isspace(*(temp - 1)))
				exit_all(a, "Wrong symbols after colors or res\n");
	}
	else
	{
		while (*(temp++) != '\n' && *(temp - 1))
			if (!ft_isspace(*(temp - 1)) && !ft_isdigit(*(temp - 1))
			&& *(temp - 1) != skip)
			{
				if (skip == ',')
					exit_all(a, "Wrong symbols in colors\n");
				else
					exit_all(a, "Wrong symbols in resoluton\n");
			}
	}
}

void	player_pos(t_cube3d *a)
{
	int i;
	int j;

	j = 0;
	i = -1;
	while (a->map.map[++i])
	{
		j = -1;
		while (a->map.map[i][++j])
		{
			if ((ft_isalpha(a->map.map[i][j])))
			{
				if (a->map.dir == 0)
					a->map.dir = a->map.map[i][j];
				else
					exit_all(a, "Double position in map\n");
				a->map.startx = j + 0.5;
				a->map.starty = i + 0.5;
			}
			if (a->map.map[i][j] == '2')
				a->sup.num += 1;
		}
	}
	a->map.row = i;
	a->map.col = j;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_extras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 00:27:19 by derrick           #+#    #+#             */
/*   Updated: 2021/03/30 22:54:20 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		exit_all(t_cube3d *a, char *s)
{
	if (a->win.mlx)
		mlx_loop_end(a->win.mlx);
	ft_free_all(a);
	if (s)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(s, 2);
	}
	if (a->img.img)
		mlx_destroy_image(a->win.mlx, a->img.img);
	if (a->win.mlx && a->win.win)
		mlx_destroy_window(a->win.mlx, a->win.win);
	ft_free(a->win.mlx);
	exit(0);
}

int		protected_strlen(const char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*addline(char *str, int diff)
{
	int		i;
	char	*add;

	i = -1;
	add = 0;
	if (!(add = malloc((protected_strlen(str) + diff + 1))))
		return (NULL);
	while (str[++i])
		add[i] = str[i];
	while (diff--)
		add[i++] = ' ';
	add[i] = '\0';
	ft_free(str);
	return (add);
}

void	mapchecker(t_cube3d *a)
{
	int i;
	int j;

	i = 0;
	while (++i < (a->map.row - 1))
	{
		j = -1;
		while (a->map.map[i][++j] != '\0')
		{
			if (!(ft_strchr("012NSEW \t", a->map.map[i][j])))
				exit_all(a, "Wrong symbols in map\n");
			if ((ft_strchr("02NSEW", a->map.map[i][j])) &&
				((ft_isspace(a->map.map[i - 1][j + 1])) ||
				ft_isspace(a->map.map[i - 1][j - 1]) ||
				ft_isspace(a->map.map[i + 1][j - 1]) ||
				ft_isspace(a->map.map[i + 1][j + 1]) ||
				ft_isspace(a->map.map[i][j - 1]) ||
				ft_isspace(a->map.map[i][j + 1]) ||
				ft_isspace(a->map.map[i - 1][j]) ||
				ft_isspace(a->map.map[i + 1][j])))
				exit_all(a, "Wrong map, sorry! Need more gold.. walls!\n");
		}
	}
}

void	parser(t_cube3d *a, char *mapfile)
{
	int	fd;

	fd = open(mapfile, O_RDONLY);
	if (fd <= 0)
		exit_all(a, "Empty file or wrong path\n");
	parse_all(fd, a);
	close(fd);
	create_map_tocheck(a);
	mapchecker(a);
	if (!(a->sup.x = malloc(sizeof(int *) * a->sup.num + 1)))
		exit_all(a, "Malloc sprite error");
	if (!(a->sup.y = malloc(sizeof(int *) * a->sup.num + 1)))
		exit_all(a, "Malloc sprite error");
	place_sprites_hexcolors(a);
}

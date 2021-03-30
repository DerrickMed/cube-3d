/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closeandforget.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:51:17 by srorscha          #+#    #+#             */
/*   Updated: 2021/03/31 01:25:29 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		check_tex_size(t_cube3d *a)
{
	if (a->sup.sprh != a->pl.texh || a->sup.sprw != a->pl.texw)
		exit_all(a, "Different texture sizes\n");
}

void		ft_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = 0;
	}
}

void		check_for_silly_mistakes(t_cube3d *a, int argc, char **argv)
{
	int len;

	if (argc == 3 && (ft_strncmp(argv[2], "--save", ft_strlen(argv[2]))))
		exit_all(a, "Invalid option\n");
	if (argc == 1 || argc > 3)
		exit_all(a, "Please count args\n");
	if (argc == 3 && (!ft_strncmp(argv[2], "--save", 6)))
		a->map.screenshot = 1;
	len = ft_strlen(argv[1]);
	if (!(argv[1][len - 4] == '.' && argv[1][len - 3] == 'c'
	&& argv[1][len - 2] == 'u' && argv[1][len - 1] == 'b'))
		exit_all(a, "Wrong map extension\n");
}

static void	ft_free_words(char **words)
{
	int b;

	b = 0;
	while (words[b])
		ft_free(words[b++]);
	ft_free(words);
}

void		ft_free_all(t_cube3d *a)
{
	if (a->map.map)
		ft_free_words(a->map.map);
	ft_free(a->map.map1d);
	if (a->pl.teximg_n)
		mlx_destroy_image(a->win.mlx, a->pl.teximg_n);
	if (a->pl.teximg_e)
		mlx_destroy_image(a->win.mlx, a->pl.teximg_e);
	if (a->pl.teximg_s)
		mlx_destroy_image(a->win.mlx, a->pl.teximg_s);
	if (a->pl.teximg_w)
		mlx_destroy_image(a->win.mlx, a->pl.teximg_w);
	if (a->sup.teximg)
		mlx_destroy_image(a->win.mlx, a->sup.teximg);
	ft_free(a->sup.y);
	ft_free(a->sup.x);
	ft_free(a->sup.zbuffer);
}

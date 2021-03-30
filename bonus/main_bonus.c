/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:42:07 by srorscha          #+#    #+#             */
/*   Updated: 2021/03/31 01:00:54 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	read_xpm(t_cube3d *a)
{
	if (!(a->pl.teximg_n = mlx_xpm_file_to_image(a->win.mlx, a->prs.n_file,
		&a->pl.texw, &a->pl.texh)))
		exit_all(a, "Wrong North texture\n");
	a->sup.sprh = a->pl.texh;
	a->sup.sprw = a->pl.texw;
	if (!(a->pl.teximg_s = mlx_xpm_file_to_image(a->win.mlx, a->prs.s_file,
		&a->pl.texw, &a->pl.texh)))
		exit_all(a, "Wrong South texture\n");
	check_tex_size(a);
	if (!(a->pl.teximg_w = mlx_xpm_file_to_image(a->win.mlx, a->prs.w_file,
		&a->pl.texw, &a->pl.texh)))
		exit_all(a, "Wrong West texture\n");
	check_tex_size(a);
	if (!(a->pl.teximg_e = mlx_xpm_file_to_image(a->win.mlx, a->prs.e_file,
		&a->pl.texw, &a->pl.texh)))
		exit_all(a, "Wrong East texture\n");
	check_tex_size(a);
	if (!(a->sup.teximg = mlx_xpm_file_to_image(a->win.mlx, a->prs.spr_file,
		&a->sup.sprw, &a->sup.sprh)))
		exit_all(a, "Wrong Sprite texture\n");
	a->sup.sprbh = a->sup.sprh;
	a->sup.sprbw = a->sup.sprw;
}

int		data_textures(t_cube3d *a)
{
	read_xpm(a);
	a->pl.tex_n = mlx_get_data_addr(a->pl.teximg_n,
		&a->img.bits_per_pixel, &a->img.line_length, &a->img.endian);
	a->pl.tex_s = mlx_get_data_addr(a->pl.teximg_s,
		&a->img.bits_per_pixel, &a->img.line_length, &a->img.endian);
	a->pl.tex_w = mlx_get_data_addr(a->pl.teximg_w,
		&a->img.bits_per_pixel, &a->img.line_length, &a->img.endian);
	a->pl.tex_e = mlx_get_data_addr(a->pl.teximg_e,
		&a->img.bits_per_pixel, &a->img.line_length, &a->img.endian);
	a->sup.tex = mlx_get_data_addr(a->sup.teximg,
		&a->img.bits_per_pixel, &a->img.line_length, &a->img.endian);
	return (0);
}

void	start_madness(t_cube3d *a)
{
	a->win.mlx = mlx_init();
	if (!(a->win.mlx))
	{
		exit_all(a, "Failed to even init, lol\n");
	}
	set_stuff(a);
	data_textures(a);
	a->img.img = mlx_new_image(a->win.mlx, a->prs.res_x, a->prs.res_y);
	a->img.addr = mlx_get_data_addr(a->img.img, &a->img.bits_per_pixel,
	&a->img.line_length, &a->img.endian);
}

int		thanks_lodev(t_cube3d *a)
{
	int		i;

	i = -1;
	screen_fps_check(a);
	allkeys(a);
	while (++i < a->prs.res_x)
	{
		ray_delta_step_side(i, a);
		raycasting(a);
		dist_height(a);
		a->sup.zbuffer[i] = a->pl.perpw;
		textures_colors(a);
		draw_line(i, a);
	}
	sprites(a);
	if (!a->map.screenshot)
		mlx_put_image_to_window(a->win.mlx, a->win.win, a->img.img, 0, 0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_cube3d	cube;

	config(&cube);
	check_for_silly_mistakes(&cube, argc, argv);
	parser(&cube, argv[1]);
	if (argc == 3 && (!ft_strncmp(argv[2], "--save", 6)))
		screenshot(&cube);
	start_madness(&cube);
	cube.win.win = mlx_new_window(cube.win.mlx, cube.prs.res_x,
		cube.prs.res_y, "Cube3d");
	mlx_do_key_autorepeatoff(cube.win.mlx);
	mlx_loop_hook(cube.win.mlx, thanks_lodev, &cube);
	mlx_hook(cube.win.win, 2, 1L << 0, keybuffer_press, &cube);
	mlx_hook(cube.win.win, 3, 1L << 1, keybuffer_release, &cube);
	mlx_hook(cube.win.win, 17, 0L, exit_allfine, &cube);
	mlx_do_sync(cube.win.mlx);
	mlx_loop(cube.win.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 00:26:59 by derrick           #+#    #+#             */
/*   Updated: 2021/03/31 00:02:59 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		rbg_hex(t_cube3d *a, int r, int g, int b)
{
	r = (r > 255) ? 255 : r;
	g = (g > 255) ? 255 : g;
	b = (b > 255) ? 255 : b;
	if (r < 0 || g < 0 || b < 0)
		exit_all(a, "Wrong colors\n");
	return (r << 16 | g << 8 | b);
}

void	set_stuff(t_cube3d *a)
{
	a->pl.x = a->map.startx;
	a->pl.y = a->map.starty;
	a->pl.texw = 64;
	a->pl.texh = 64;
	a->pl.bmoves = 0.01;
	a->pl.brots = 0.005;
	if (a->map.dir == 'S' && (a->pl.diry = 1))
		a->pl.planex = -0.66;
	if (a->map.dir == 'E' && (a->pl.dirx = 1))
		a->pl.planey = 0.66;
	if (a->map.dir == 'W' && (a->pl.dirx = -1))
		a->pl.planey = -0.66;
	if (a->map.dir == 'N' && (a->pl.diry = -1))
		a->pl.planex = 0.66;
	if (!(a->sup.zbuffer = malloc(sizeof(float *) * a->prs.res_x + 1)))
		exit_all(a, "Malloc error");
}

void	textures_colors(t_cube3d *a)
{
	float	wallx;

	if (a->pl.side == 0)
		wallx = a->pl.y + a->pl.perpw * a->pl.rdiry;
	else
		wallx = a->pl.x + a->pl.perpw * a->pl.rdirx;
	wallx -= floor(wallx);
	a->pl.texx = (int)(wallx * a->pl.texw);
	if ((a->pl.side == 0 && a->pl.rdirx > 0)
		|| (a->pl.side == 1 && a->pl.rdiry < 0))
		a->pl.texx = a->pl.texw - a->pl.texx - 1;
	a->pl.step = 1.0 * a->pl.texh / a->pl.wheight;
	a->pl.texpos = (a->pl.dstart - a->prs.res_y / 2 + a->pl.wheight / 2)
		* a->pl.step;
	if (a->pl.side == 1 && (a->pl.mapy > a->pl.y))
		a->pl.color = (int *)a->pl.tex_s;
	else if (a->pl.side == 1 && (a->pl.mapy < a->pl.y))
		a->pl.color = (int *)a->pl.tex_n;
	else if (a->pl.side == 0 && (a->pl.mapx > a->pl.x))
		a->pl.color = (int *)a->pl.tex_e;
	else
		a->pl.color = (int *)a->pl.tex_w;
	a->sup.color = (int *)a->sup.tex;
}

int		allkeys(t_cube3d *a)
{
	a->pl.moves = a->pl.bmoves * a->kbuf.shift * a->kbuf.frametime;
	a->pl.rots = a->pl.brots * a->kbuf.frametime;
	a->pl.oldplanex = a->pl.planex;
	if (a->kbuf.esc)
		exit_all(a, 0);
	if (a->kbuf.up)
		up_down(a, KEY_W);
	if (a->kbuf.down)
		up_down(a, KEY_S);
	if (a->kbuf.left)
		rotation(a, KEY_A);
	if (a->kbuf.right)
		rotation(a, KEY_D);
	if (a->kbuf.q)
		strafe(a, KEY_Q);
	if (a->kbuf.e)
		strafe(a, KEY_E);
	return (1);
}

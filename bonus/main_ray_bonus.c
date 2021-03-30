/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ray_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 00:26:52 by derrick           #+#    #+#             */
/*   Updated: 2021/03/30 23:52:22 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	dist_height(t_cube3d *a)
{
	if (a->pl.side == 0)
		a->pl.perpw = (a->pl.mapx - a->pl.x +
		(1 - a->pl.stepx) / 2) / a->pl.rdirx;
	else
		a->pl.perpw = (a->pl.mapy - a->pl.y +
		(1 - a->pl.stepy) / 2) / a->pl.rdiry;
	if (a->pl.perpw == 0)
		a->pl.perpw = 0.01;
	a->pl.wheight = (a->prs.res_y / a->pl.perpw);
	a->pl.wheight = a->pl.wheight * a->prs.res_x / a->prs.res_y * 3 / 4;
	a->pl.dstart = -a->pl.wheight / 2 + a->prs.res_y / 2;
	if (a->pl.dstart < 0)
		a->pl.dstart = 0;
	a->pl.dend = a->pl.wheight / 2 + a->prs.res_y / 2;
	if (a->pl.dend >= a->prs.res_y)
		a->pl.dend = a->prs.res_y - 1;
}

void	raycasting(t_cube3d *a)
{
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		if (a->pl.sidedx < a->pl.sidedy)
		{
			a->pl.sidedx += a->pl.ddistx;
			a->pl.mapx += a->pl.stepx;
			a->pl.side = 0;
		}
		else
		{
			a->pl.sidedy += a->pl.ddisty;
			a->pl.mapy += a->pl.stepy;
			a->pl.side = 1;
		}
		if (a->map.map[a->pl.mapy][a->pl.mapx] == '1')
			hit = 1;
	}
}

void	ray_delta_step_side(int i, t_cube3d *a)
{
	a->pl.camx = 2 * i / (float)a->prs.res_x - 1;
	a->pl.rdirx = a->pl.dirx + a->pl.planex * a->pl.camx;
	a->pl.rdiry = a->pl.diry + a->pl.planey * a->pl.camx;
	a->pl.mapx = (int)a->pl.x;
	a->pl.mapy = (int)a->pl.y;
	a->pl.ddistx = fabs(1 / a->pl.rdirx);
	a->pl.ddisty = fabs(1 / a->pl.rdiry);
	if (a->pl.rdirx < 0)
		if ((a->pl.stepx = -1))
			a->pl.sidedx = (a->pl.x - a->pl.mapx) * a->pl.ddistx;
	if (a->pl.rdirx >= 0)
		if ((a->pl.stepx = 1))
			a->pl.sidedx = (a->pl.mapx + 1.0 - a->pl.x) * a->pl.ddistx;
	if (a->pl.rdiry < 0)
		if ((a->pl.stepy = -1))
			a->pl.sidedy = (a->pl.y - a->pl.mapy) * a->pl.ddisty;
	if (a->pl.rdiry >= 0)
		if ((a->pl.stepy = 1))
			a->pl.sidedy = (a->pl.mapy + 1.0 - a->pl.y) * a->pl.ddisty;
}

void	draw_line(int i, t_cube3d *a)
{
	int xy;
	int y;

	xy = -1;
	y = a->pl.dstart - 1;
	while (++xy < y + 1)
		my_mlx_pixel_put(&a->img, i, xy, a->prs.c_color);
	while (++y < (int)a->pl.dend)
	{
		a->pl.texy = a->pl.texpos;
		a->pl.texpos += a->pl.step;
		if (a->pl.color[a->pl.texy * a->pl.texh + a->pl.texx])
			my_mlx_pixel_put(&a->img, i, y, a->pl.color[a->pl.texy
				* a->pl.texh + a->pl.texx]);
	}
	while (++y < a->prs.res_y)
		my_mlx_pixel_put(&a->img, i, y, a->prs.f_color);
}

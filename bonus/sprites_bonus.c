/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 00:28:07 by derrick           #+#    #+#             */
/*   Updated: 2021/03/30 23:59:16 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void			sevenup_dstart(t_cube3d *a)
{
	a->sup.dstarty = -a->sup.sprh / 2 + a->prs.res_y / 2
	+ a->sup.vmovescr;
	a->sup.dstarty = (a->sup.dstarty < 0) ? 0 : a->sup.dstarty;
	a->sup.dendy = a->sup.sprh / 2 + a->prs.res_y / 2
		+ a->sup.vmovescr;
	if (a->sup.dendy >= a->prs.res_y)
		a->sup.dendy = a->prs.res_y - 1;
	a->sup.sprw = fabs((float)a->prs.res_y / a->sup.transy);
	a->sup.sprw = a->sup.sprw * a->prs.res_x / a->prs.res_y * 3 / 4;
	a->sup.dstartx = -a->sup.sprw / 2 + a->sup.sprscrx;
	a->sup.dstartx = (a->sup.dstartx < 0) ? 0 : a->sup.dstartx;
	a->sup.dendx = a->sup.sprw / 2 + a->sup.sprscrx;
	if (a->sup.dendx >= a->prs.res_y)
		a->sup.dendx = a->prs.res_x - 1;
}

static float	sevenup_dist(t_cube3d *a, int i)
{
	return ((a->pl.x - a->sup.x[i]) *
			(a->pl.x - a->sup.x[i]) + (a->pl.y - a->sup.y[i]) *
			(a->pl.y - a->sup.y[i]));
}

void			sevenup_sort(t_cube3d *a)
{
	int		j;
	int		i;
	float	x;

	i = -1;
	while (++i < a->sup.num - 1)
	{
		j = i;
		a->sup.sprdist = sevenup_dist(a, i);
		while (++j < a->sup.num)
			if (sevenup_dist(a, j) > a->sup.sprdist)
			{
				x = a->sup.x[i];
				a->sup.x[i] = a->sup.x[j];
				a->sup.x[j] = x;
				x = a->sup.y[i];
				a->sup.y[i] = a->sup.y[j];
				a->sup.y[j] = x;
			}
	}
}

void			sevenup_go_live(t_cube3d *a)
{
	int		y;
	int		c;

	a->sup.sprline = a->sup.dstartx - 1;
	while (++a->sup.sprline < a->sup.dendx)
	{
		a->sup.texx = (int)((a->sup.sprline - (-a->sup.sprw / 2
		+ a->sup.sprscrx)) * a->sup.sprbh / a->sup.sprw);
		y = a->sup.dstarty - 1;
		if (a->sup.transy > 0 && a->sup.sprline > 0 && a->sup.sprline <
			a->prs.res_x && a->sup.transy < a->sup.zbuffer[a->sup.sprline]
				&& a->sup.texx < a->sup.sprbw)
			while (++y < a->sup.dendy)
			{
				c = (y - a->sup.vmovescr) * 256 - a->prs.res_y * 128 +
					a->sup.sprh * 128;
				if (c < 0)
					c = 0;
				a->sup.texy = ((c * a->sup.sprbh) / a->sup.sprh) / 256;
				if (a->sup.color[a->sup.sprbw * a->sup.texy + a->sup.texx])
					my_mlx_pixel_put(&a->img, a->sup.sprline, y,
					a->sup.color[a->sup.sprbw * a->sup.texy + a->sup.texx]);
			}
	}
}

void			sprites(t_cube3d *a)
{
	int i;

	i = -1;
	sevenup_sort(a);
	while (++i < a->sup.num)
	{
		a->sup.spry = a->sup.y[i] - a->pl.y;
		a->sup.sprx = a->sup.x[i] - a->pl.x;
		a->sup.invdet = 1.0 / (a->pl.planex * a->pl.diry
		- a->pl.dirx * a->pl.planey);
		a->sup.transx = a->sup.invdet * (a->pl.diry *
		a->sup.sprx - a->pl.dirx * a->sup.spry);
		a->sup.transy = a->sup.invdet * (-a->pl.planey *
		a->sup.sprx + a->pl.planex * a->sup.spry);
		a->sup.sprscrx = (int)((a->prs.res_x / 2) *
		(1 + a->sup.transx / a->sup.transy));
		a->sup.vmovescr = 94.0 / a->sup.transy;
		a->sup.sprh = fabs((float)a->prs.res_y / a->sup.transy);
		a->sup.sprh = a->sup.sprh * a->prs.res_x / a->prs.res_y * 3 / 4;
		sevenup_dstart(a);
		sevenup_go_live(a);
	}
}

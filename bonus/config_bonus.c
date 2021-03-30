/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:40:23 by srorscha          #+#    #+#             */
/*   Updated: 2021/03/31 00:59:02 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	config_2(t_cube3d *a)
{
	a->pl.dstart = 0;
	a->pl.dend = 0;
	a->pl.wheight = 0;
	a->pl.tex_n = NULL;
	a->pl.tex_s = NULL;
	a->pl.tex_e = NULL;
	a->pl.tex_w = NULL;
	a->pl.mapx = 0;
	a->pl.mapy = 0;
	a->pl.wheight = 0;
	a->pl.x = 0;
	a->pl.y = 0;
	a->pl.dirx = 0;
	a->pl.diry = 0;
	a->pl.rdirx = 0;
	a->pl.rdiry = 0;
	a->pl.perpw = 0;
	a->pl.mapx = 0;
	a->pl.mapy = 0;
	a->pl.dirx = 0;
	a->pl.oldplanex = 0;
	a->pl.olddirx = 0;
	a->pl.planex = 0;
	a->pl.planey = 0;
	a->pl.color = NULL;
}

void	config_3(t_cube3d *a)
{
	a->pl.texx = 0;
	a->pl.texy = 0;
	a->pl.side = 0;
	a->pl.step = 0;
	a->pl.texpos = 0;
	a->prs.res_x = 0;
	a->prs.res_y = 0;
	a->prs.c_r = -1;
	a->prs.c_g = -1;
	a->prs.c_b = -1;
	a->prs.f_r = -1;
	a->prs.s_file[0] = 0;
	a->prs.e_file[0] = 0;
	a->prs.w_file[0] = 0;
	a->prs.n_file[0] = 0;
	a->prs.spr_file[0] = 0;
	a->prs.flag = 0;
	a->kbuf.esc = 0;
	a->kbuf.left = 0;
	a->kbuf.right = 0;
	a->kbuf.up = 0;
	a->kbuf.down = 0;
	a->kbuf.q = 0;
	a->kbuf.e = 0;
}

void	config_4(t_cube3d *a)
{
	a->prs.f_g = -1;
	a->prs.f_b = -1;
	a->prs.c_color = 0;
	a->prs.f_color = 0;
	a->img.img = NULL;
	a->img.addr = NULL;
	a->img.bits_per_pixel = 0;
	a->img.line_length = 0;
	a->img.endian = 0;
	a->pl.color = NULL;
	a->map.map1d = NULL;
	a->map.col = 0;
	a->map.row = 0;
	a->map.dir = 0;
	a->map.startx = 0;
	a->map.starty = 0;
	a->map.map = NULL;
	a->map.screenshot = 0;
	a->sup.teximg = 0;
	a->pl.teximg_w = 0;
	a->pl.teximg_e = 0;
	a->pl.teximg_n = 0;
	a->pl.teximg_s = 0;
}

void	config_5(t_cube3d *a)
{
	a->sup.num = 0;
	a->sup.tex = 0;
	a->sup.sprw = 0;
	a->sup.sprbh = 0;
	a->sup.sprbw = 0;
	a->sup.sprh = 0;
	a->sup.x = NULL;
	a->sup.y = NULL;
	a->sup.invdet = 1;
	a->sup.transx = 0;
	a->sup.transy = 0;
	a->sup.sprscrx = 0;
	a->sup.vmovescr = 0;
	a->sup.dstarty = 0;
	a->sup.dendy = 0;
	a->sup.dstartx = 0;
	a->sup.dendx = 0;
	a->sup.sprline = 0;
	a->sup.texx = 0;
	a->sup.texy = 0;
	a->sup.sprdist = 0;
	a->sup.zbuffer = NULL;
}

void	config(t_cube3d *a)
{
	a->win.mlx = NULL;
	a->win.win = NULL;
	a->pl.camx = 0;
	a->pl.texx = 0;
	a->pl.texy = 0;
	a->pl.rdiry = 0;
	a->pl.rdirx = 0;
	a->pl.mapx = 0;
	a->pl.mapy = 0;
	a->pl.sidedx = 0;
	a->pl.sidedy = 0;
	a->pl.ddistx = 0;
	a->pl.ddisty = 0;
	a->pl.perpw = 0;
	a->pl.stepx = 0;
	a->pl.stepy = 0;
	a->kbuf.time = 0;
	a->kbuf.oldtime = 0;
	a->kbuf.frametime = 0;
	a->kbuf.shift = 1;
	config_2(a);
	config_3(a);
	config_4(a);
	config_5(a);
}

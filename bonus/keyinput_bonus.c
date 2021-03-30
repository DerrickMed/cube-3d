/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyinput_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:53:30 by srorscha          #+#    #+#             */
/*   Updated: 2021/03/30 18:42:05 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		keybuffer_press(int keys, t_cube3d *a)
{
	if (keys == KEY_S || keys == KEY_DOWN)
		a->kbuf.down = 1;
	if (keys == KEY_W || keys == KEY_UP)
		a->kbuf.up = 1;
	if (keys == KEY_ESC || keys == KEY_X)
		a->kbuf.esc = 1;
	if (keys == KEY_A || keys == KEY_LEFT)
		a->kbuf.left = 1;
	if (keys == KEY_D || keys == KEY_RIGHT)
		a->kbuf.right = 1;
	if (keys == KEY_Q)
		a->kbuf.q = 1;
	if (keys == KEY_E)
		a->kbuf.e = 1;
	if (keys == 65505)
		a->kbuf.shift = 1.7;
	return (1);
}

int		keybuffer_release(int keys, t_cube3d *a)
{
	if (keys == KEY_W || keys == KEY_UP)
		a->kbuf.up = 0;
	if (keys == KEY_S || keys == KEY_DOWN)
		a->kbuf.down = 0;
	if (keys == KEY_A || keys == KEY_LEFT)
		a->kbuf.left = 0;
	if (keys == KEY_D || keys == KEY_RIGHT)
		a->kbuf.right = 0;
	if (keys == KEY_Q)
		a->kbuf.q = 0;
	if (keys == KEY_E)
		a->kbuf.e = 0;
	if (keys == 65505)
		a->kbuf.shift = 1;
	return (1);
}

void	up_down(t_cube3d *a, int keys)
{
	if (keys == KEY_W || keys == KEY_UP)
	{
		if (!ft_strchr("12", a->map.map[(int)a->pl.y][(int)(a->pl.x +
		a->pl.dirx * (a->pl.moves * 1.1))]))
			a->pl.x += a->pl.dirx * a->pl.moves;
		if (!ft_strchr("12", a->map.map[(int)(a->pl.y + a->pl.diry *
		(a->pl.moves * 1.1))][(int)a->pl.x]))
			a->pl.y += a->pl.diry * a->pl.moves;
	}
	if (keys == KEY_S || keys == KEY_DOWN)
	{
		if (!ft_strchr("12", a->map.map[(int)a->pl.y][(int)(a->pl.x -
		a->pl.dirx * (a->pl.moves * 1.1))]))
			a->pl.x -= a->pl.dirx * a->pl.moves;
		if (!ft_strchr("12", a->map.map[(int)(a->pl.y - a->pl.diry *
		(a->pl.moves * 1.1))][(int)a->pl.x]))
			a->pl.y -= a->pl.diry * a->pl.moves;
	}
}

void	rotation(t_cube3d *a, int keys)
{
	a->pl.olddirx = a->pl.dirx;
	if (keys == KEY_D)
	{
		a->pl.dirx = a->pl.dirx * cos(a->pl.rots) -
			a->pl.diry * sin(a->pl.rots);
		a->pl.diry = a->pl.olddirx * sin(a->pl.rots) +
			a->pl.diry * cos(a->pl.rots);
		a->pl.oldplanex = a->pl.planex;
		a->pl.planex = a->pl.planex * cos(a->pl.rots) -
			a->pl.planey * sin(a->pl.rots);
		a->pl.planey = a->pl.oldplanex * sin(a->pl.rots) +
			a->pl.planey * cos(a->pl.rots);
	}
	if (keys == KEY_A)
	{
		a->pl.dirx = a->pl.dirx * cos(-a->pl.rots) -
			a->pl.diry * sin(-a->pl.rots);
		a->pl.diry = a->pl.olddirx * sin(-a->pl.rots) +
			a->pl.diry * cos(-a->pl.rots);
		a->pl.oldplanex = a->pl.planex;
		a->pl.planex = a->pl.planex * cos(-a->pl.rots) -
			a->pl.planey * sin(-a->pl.rots);
		a->pl.planey = a->pl.oldplanex * sin(-a->pl.rots) +
			a->pl.planey * cos(-a->pl.rots);
	}
}

void	strafe(t_cube3d *a, int keys)
{
	if (keys == KEY_Q)
	{
		if (!ft_strchr("12", a->map.map[(int)(a->pl.y - a->pl.dirx *
		(a->pl.moves * 1.1))][(int)a->pl.x]))
			a->pl.y -= a->pl.dirx * a->pl.moves;
		if (!ft_strchr("12", a->map.map[(int)a->pl.y][(int)(a->pl.x +
		a->pl.diry * (a->pl.moves * 1.1))]))
			a->pl.x += a->pl.diry * a->pl.moves;
	}
	if (keys == KEY_E)
	{
		if (!ft_strchr("12", a->map.map[(int)(a->pl.y + a->pl.dirx *
		(a->pl.moves * 1.1))][(int)a->pl.x]))
			a->pl.y += a->pl.dirx * a->pl.moves;
		if (!ft_strchr("12", a->map.map[(int)a->pl.y][(int)(a->pl.x -
		a->pl.diry * (a->pl.moves * 1.1))]))
			a->pl.x -= a->pl.diry * a->pl.moves;
	}
}

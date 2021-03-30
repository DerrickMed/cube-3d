/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:21:27 by srorscha          #+#    #+#             */
/*   Updated: 2021/03/31 00:25:43 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	head(int fd, t_cube3d *a, int res, int size)
{
	char	header[54];

	ft_bzero(header, 54);
	header[0] = 0x42;
	header[1] = 0x4D;
	ft_memcpy(&header[2], &size, 4);
	header[10] = 0x36;
	header[14] = 0x28;
	ft_memcpy(&header[18], &res, 4);
	res = -a->prs.res_y;
	ft_memcpy(&header[22], &res, 4);
	header[26] = 0x01;
	header[28] = 0x20;
	write(fd, header, 54);
}

void	screenshot(t_cube3d *a)
{
	int		fd;
	int		res;
	int		size;

	if (a->prs.res_x > 12000)
		a->prs.res_x = 12000;
	if (a->prs.res_y > 10000)
		a->prs.res_y = 10000;
	start_madness(a);
	thanks_lodev(a);
	res = a->prs.res_x;
	size = 54 + (a->prs.res_x * a->prs.res_y) * 4;
	if ((fd = open("screenshot.bmp", O_CREAT | O_RDWR, 0666)) < 0)
		exit_all(a, "Screenshot, error");
	head(fd, a, res, size);
	write(fd, a->img.addr, (a->prs.res_x * a->prs.res_y * 4));
	close(fd);
	exit_all(a, 0);
}

void	screen_fps_check(t_cube3d *a)
{
	a->kbuf.oldtime = a->kbuf.time;
	a->kbuf.time = clock();
	a->kbuf.frametime = (a->kbuf.time - a->kbuf.oldtime) /
		(a->prs.res_x + a->prs.res_y);
}

int		exit_allfine(t_cube3d *a)
{
	if (a->win.mlx)
		mlx_loop_end(a->win.mlx);
	ft_free_all(a);
	if (a->img.img)
		mlx_destroy_image(a->win.mlx, a->img.img);
	if (a->win.mlx && a->win.win)
		mlx_destroy_window(a->win.mlx, a->win.win);
	ft_free(a->win.mlx);
	exit(0);
}

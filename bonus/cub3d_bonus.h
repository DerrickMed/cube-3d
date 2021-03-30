/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:33:41 by srorscha          #+#    #+#             */
/*   Updated: 2021/03/31 00:55:33 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <time.h>
# include "../mlxlinux/mlx.h"
# include "../libft/libft.h"

# define KEY_ESC 65307
# define KEY_X 120
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_E 101
# define KEY_Q 113
# define RESX_MAX 2560
# define RESY_MAX 1440
# define RESX_MIN 100
# define RESY_MIN 100

typedef struct		s_vars
{
	void			*mlx;
	void			*win;
}					t_vars;

typedef struct		s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_img;

typedef struct		s_player
{
	unsigned int	mapx;
	unsigned int	mapy;
	int				texx;
	int				texy;
	int				texw;
	int				texh;
	int				*color;
	int				side;
	float			wheight;
	float			x;
	float			y;
	float			dirx;
	float			diry;
	float			rdirx;
	float			rdiry;
	float			perpw;
	float			dstart;
	float			dend;
	float			sidedx;
	float			sidedy;
	int				stepx;
	int				stepy;
	float			ddistx;
	float			ddisty;
	float			step;
	float			texpos;
	void			*tex_n;
	void			*tex_s;
	void			*tex_e;
	void			*tex_w;
	void			*teximg_n;
	void			*teximg_s;
	void			*teximg_e;
	void			*teximg_w;
	float			planex;
	float			planey;
	float			camx;
	float			moves;
	float			rots;
	float			bmoves;
	float			brots;
	float			oldplanex;
	float			olddirx;
}					t_player;

typedef struct		s_parse
{
	char			**map;
	char			*map1d;
	float			startx;
	float			starty;
	char			dir;
	int				row;
	int				col;
	int				screenshot;
}					t_parse;

typedef struct		s_keys
{
	int				esc;
	int				left;
	int				right;
	int				up;
	int				down;
	int				e;
	int				q;
	double			frametime;
	int				time;
	int				oldtime;
	float			shift;
}					t_keys;

typedef struct		s_mapparts
{
	int				flag;
	int				res_x;
	int				res_y;
	int				c_r;
	int				c_g;
	int				c_b;
	int				f_r;
	int				f_g;
	int				f_b;
	int				c_color;
	int				f_color;
	char			n_file[5000];
	char			s_file[5000];
	char			w_file[5000];
	char			e_file[5000];
	char			spr_file[5000];
}					t_mapparts;

typedef struct		s_sprites
{
	float			transx;
	float			transy;
	float			sprx;
	float			spry;
	float			invdet;
	float			sprdist;
	float			*zbuffer;
	float			*x;
	float			*y;
	float			dstarty;
	float			dendy;
	float			dstartx;
	float			dendx;
	int				num;
	int				*color;
	int				sprw;
	int				sprh;
	int				sprbh;
	int				sprbw;
	float			sprscrx;
	float			vmovescr;
	int				sprline;
	int				texx;
	int				texy;
	void			*tex;
	void			*teximg;
}					t_sprites;

typedef struct		s_cube3d
{
	t_player		pl;
	t_vars			win;
	t_img			img;
	t_parse			map;
	t_mapparts		prs;
	t_sprites		sup;
	t_keys			kbuf;
}					t_cube3d;

/*
**	get_next_line
*/

int					get_next_line(int fd, char **line);
char				*gnl_strjoin(char *s1, char const *s2);

/*
**	main
*/

void				read_xpm(t_cube3d *a);
int					data_textures(t_cube3d *a);
void				start_madness(t_cube3d *a);
int					thanks_lodev(t_cube3d *a);

/*
**	main_utlis
*/

void				set_stuff(t_cube3d *a);
int					rbg_hex(t_cube3d *a, int r, int g, int b);
void				my_mlx_pixel_put(t_img *data, int x, int y, int color);
void				textures_colors(t_cube3d *a);
int					allkeys(t_cube3d *a);

/*
**	main_ray
*/

void				dist_height(t_cube3d *a);
void				raycasting(t_cube3d *a);
void				ray_delta_step_side(int i, t_cube3d *a);
void				draw_line(int i, t_cube3d *a);

/*
**	keyinput
*/

void				up_down(t_cube3d *a, int keys);
void				rotation(t_cube3d *a, int keys);
void				strafe(t_cube3d *a, int keys);
int					keybuffer_press (int keys, t_cube3d *a);
int					keybuffer_release (int keys, t_cube3d *a);

/*
**	sprites
*/

void				sevenup_dstart(t_cube3d *a);
void				sevenup_sort(t_cube3d *a);
void				sevenup_go_live(t_cube3d *a);
void				sprites(t_cube3d *a);

/*
**	config
*/

void				config(t_cube3d *a);
void				config_2(t_cube3d *a);
void				config_3(t_cube3d *a);
void				config_4(t_cube3d *a);
void				config_5(t_cube3d *a);

/*
**	closeandforget
*/

void				ft_free(void *ptr);
void				ft_free_all(t_cube3d *a);
void				check_for_silly_mistakes(t_cube3d *a,
					int argc, char **argv);
void				check_tex_size(t_cube3d *a);

/*
**	parser extras
*/

int					protected_strlen(const char *s);
int					exit_all(t_cube3d *a, char *s);
char				*addline(char *str, int diff);
void				mapchecker(t_cube3d *a);
void				parser(t_cube3d *a, char *mapfile);

/*
**	parser1
*/

int					special_atoi(char **str);
void				parse_res(int fd, t_cube3d *a);
void				read_path(int fd, char *path, t_cube3d *a);
void				parse_ceil_color(int fd, t_cube3d *a);
void				parse_floor_color(int fd, t_cube3d *a);

/*
**	parser2
*/

void				mapparser(int fd, t_cube3d *a);
void				check_letters(char *temp, t_cube3d *a, char skip);
void				player_pos(t_cube3d *a);

/*
**	parser3
*/

void				parse_path(int fd, t_cube3d *a, char line);
void				parse_all(int fd, t_cube3d *a);
void				create_map_tocheck(t_cube3d *a);
void				place_sprites_hexcolors(t_cube3d *a);
void				check_flags(int fd, t_cube3d *a, char line);

/*
**	screen
*/

void				screenshot(t_cube3d *a);
void				head(int fd, t_cube3d *a, int res, int size);
void				screen_fps_check(t_cube3d *a);
int					exit_allfine(t_cube3d *a);

#endif

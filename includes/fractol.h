/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:58:19 by ndremora          #+#    #+#             */
/*   Updated: 2019/06/03 16:19:29 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "/usr/local/include/mlx.h"
# include "mlx_keys.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
#include <pthread.h>

# define WIDTH 1000
# define HEIGHT 1000
# define POW(a) (a * a)

typedef struct	s_dot
{
	double		r;
	double		i;
}				t_dot;

typedef struct	s_col
{
	int			red;
	int			green;
	int			blue;
}				t_col;

typedef struct	s_fcl
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*image_data;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	double		zoom;
	int			max;
	double		x_move;
	double		y_move;
	double		mx;
	double		my;
	int			count;
	int			f;
	int			click;
	int			zoom_t;
	double		rat;
	int			half_w;
	int			half_h;
	double		zoom_w;
	double		zoom_h;
	int			cross;
	int			threads;
}				t_fcl;

typedef struct s_thread_data
{
	int			index;
	pthread_t	thrd;
	t_fcl		*fcl;
}				t_thread_data;

int				move_mouse(int x, int y, t_fcl *fcl);
void			fractal_init(t_fcl *fcl);
void			fractal2(t_fcl *fcl, FILE *fp);
int				draw2(t_fcl *fcl);
void			asctohex(char a, char *s, int i);
void			add_to_map(t_col *col, int i, FILE *fp);
void			draw_cross(t_fcl *fcl);
void			check_usage(t_fcl *fcl, char **av, int i);
void			win2(t_fcl *fcl, int x, int y, t_col *col);
void			pixel_to_img3(t_fcl *fcl, int x, int y, t_col *c);
void			pixel_to_img2(t_fcl *fcl, int x, int y, t_col *c);
int				deal_mouse(int key, int x, int y, t_fcl *fcl);
void			change_max(int key, t_fcl *fcl);
void			pxl_to_i(t_fcl *app, int x, int y, t_col *c);
void			color_func2(int i, int max, t_col *col);
void			color_func(int i, double p, t_col *col);
int				ship(t_fcl *fcl, int x, int y);
int				newton(t_fcl *fcl, int x, int y);
int				draw(t_fcl *fcl);
void			fractal(t_fcl *fcl);
int				mandelbrot(t_fcl *fcl, int x, int y);
int				julia(t_fcl *fcl, int x, int y);
int				deal_key(int key, t_fcl *fcl);
void			move(int key, t_fcl *fcl);
void			mlx_hooks(t_fcl *fcl);
void			mlx_hooks2(t_fcl *fcl, t_fcl *fcl2);
void			zoom(int key, t_fcl *fcl);
int				close_x(void *param);
void			ft_error(char *str);
void			fractal_init2(t_fcl *fcl, t_fcl *fcl2);
void			*calculate(void *fcl);
void			fractal3(t_fcl *fcl);


#endif

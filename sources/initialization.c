/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:52:05 by ndremora          #+#    #+#             */
/*   Updated: 2019/06/03 14:49:54 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	check_usage(t_fcl *fcl, char **av, int i)
{
	fcl->f = 0;
	if ((ft_strcmp(av[i], "mandelbrot")) == 0)
		fcl->f = 1;
	else if ((ft_strcmp(av[i], "julia")) == 0)
		fcl->f = 2;
	else if ((ft_strcmp(av[i], "ship")) == 0)
		fcl->f = 3;
	else if ((ft_strcmp(av[i], "newton")) == 0)
		fcl->f = 4;
	else if ((ft_strcmp(av[i], "combo")) == 0)
		fcl->f = 5;
	else if (fcl->f == 0)
		ft_error("Wrong usage");
}

void	fractal_init(t_fcl *fcl)
{
	fcl->x_move = 0;
	fcl->y_move = 0;
	fcl->max = 50;
	fcl->count = 1;
	fcl->zoom = 1;
	fcl->mx = 0;
	fcl->my = 0;
	fcl->click = 0;
	fcl->zoom_t = 40;
	fcl->rat = (double)WIDTH / (double)HEIGHT;
	fcl->half_w = WIDTH / 2;
	fcl->half_h = HEIGHT / 2;
	fcl->cross = 1;
	fcl->threads = 4;
	if (!(fcl->mlx = mlx_init()))
		ft_error("Fractol initialization error");
	if (!(fcl->win = mlx_new_window(fcl->mlx, WIDTH, HEIGHT, \
			"Fract'ol ndremora school21")))
		ft_error("Fractol initialization error");
	if (!(fcl->img = mlx_new_image(fcl->mlx, WIDTH, HEIGHT)))
		ft_error("Fract'ol image creation error");
	fcl->image_data = mlx_get_data_addr(fcl->img, &(fcl->bits_per_pixel), \
			&(fcl->size_line), &(fcl->endian));
}

void	fractal_init2(t_fcl *fcl, t_fcl *fcl2)
{
	fcl->x_move = 0;
	fcl->y_move = 0;
	fcl->max = 30;
	fcl->count = 1;
	fcl->zoom = 1;
	fcl->mx = 0;
	fcl->my = 0;
	fcl->click = 0;
	fcl->zoom_t = 40;
	fcl->rat = (double)WIDTH / (double)HEIGHT;
	fcl->half_w = WIDTH / 2;
	fcl->half_h = HEIGHT / 2;
	fcl->cross = 1;
	fcl->threads = 5;
	if (!(fcl->win = mlx_new_window(fcl2->mlx, WIDTH, HEIGHT, \
			"Fract'ol ndremora school21")))
		ft_error("Fractol initialization error");
	if (!(fcl->img = mlx_new_image(fcl2->mlx, WIDTH, HEIGHT)))
		ft_error("Fract'ol image creation error");
	fcl->image_data = mlx_get_data_addr(fcl->img, &(fcl->bits_per_pixel), \
			&(fcl->size_line), &(fcl->endian));
}

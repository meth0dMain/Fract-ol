/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 09:21:06 by ndremora          #+#    #+#             */
/*   Updated: 2019/06/03 18:35:06 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include  <time.h>

int		draw(t_fcl *fcl)
{
	clock_t begin = clock();
	fcl->zoom_w = 0.25 * fcl->zoom * WIDTH;
	fcl->zoom_h = 0.25 * fcl->zoom * HEIGHT;
	fractal3(fcl);
	mlx_put_image_to_window(fcl->mlx, fcl->win, fcl->img, 0, 0);
	if (fcl->cross % 2 == 0)
		draw_cross(fcl);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%f\n", time_spent);
	mlx_string_put(fcl->mlx, fcl->win, 10, 8, 0x777777, "zoom:");
	mlx_string_put(fcl->mlx, fcl->win, 70, 8, 0x777777, ft_itoa(fcl->zoom));
	mlx_string_put(fcl->mlx, fcl->win, 10, 25, 0x777777, "max:");
	mlx_string_put(fcl->mlx, fcl->win, 70, 25, 0x777777, ft_itoa(fcl->max));
	return (0);
}

void	draw_cross(t_fcl *fcl)
{
	int i;
	int index;

	i = -1;
	while (++i < WIDTH)
	{
		index = (i * 4 + fcl->size_line * HEIGHT / 2);
		fcl->image_data[index] = 0xF;
		fcl->image_data[index + 1] = 0xF;
		fcl->image_data[index + 2] = 0xF;
	}
	i = -1;
	while (++i < HEIGHT)
	{
		index = (i * WIDTH * 2 + fcl->size_line * HEIGHT / 2);
		fcl->image_data[index] = 0xF;
		fcl->image_data[index + 1] = 0xF;
		fcl->image_data[index + 2] = 0xF;
		index = (i * WIDTH * 2 + fcl->size_line);
		fcl->image_data[index] = 0xF;
		fcl->image_data[index + 1] = 0xF;
		fcl->image_data[index + 2] = 0xF;
	}
	mlx_put_image_to_window(fcl->mlx, fcl->win, fcl->img, 0, 0);
}

void	*calculate(void *threads)
{
	int x;
	int y;
	int i;
	t_col col;
	t_thread_data *new_th = threads;

	y = (new_th->index) * HEIGHT / new_th->fcl->threads;
	while (y < HEIGHT / new_th->fcl->threads * (new_th->index + 1))
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (new_th->fcl->f == 2)
				i = julia(new_th->fcl, x, y);
			else if (new_th->fcl->f == 3)
				i = ship(new_th->fcl, x, y);
			else if (new_th->fcl->f == 4)
				i = newton(new_th->fcl, x, y);
			else
				i = mandelbrot(new_th->fcl, x, y);
			//color_func2(i,fcl->max ,&col);
			color_func(i, new_th->fcl->count * 0.25, &col);
			(new_th->fcl->f == 5) ? (win2(new_th->fcl, x, y, &col)) :\
			(pxl_to_i(new_th->fcl, x, y, &col));
		}
		y++;
	}
	return (NULL);
}

void	fractal3(t_fcl *fcl)
{
	t_thread_data *threads;
	int i;

	threads = (t_thread_data *)malloc(sizeof(t_thread_data) * fcl->threads);
	i = 0;
	while (i < fcl->threads)
	{
		threads[i].index = i;
		threads[i].fcl = fcl;
		pthread_create(&(threads[i].thrd), NULL, calculate, (void *)&threads[i]);
		i++;
	}
	while (i--)
		pthread_join(threads[i].thrd, NULL);
	free(threads);
}

void	pxl_to_i(t_fcl *app, int x, int y, t_col *c)
{
	int	index;

	index = x * 4 + app->size_line * y;
	app->image_data[index] = c->red;
	app->image_data[index + 1] = c->green;
	app->image_data[index + 2] = c->blue;
}

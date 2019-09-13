/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 09:57:23 by ndremora          #+#    #+#             */
/*   Updated: 2019/06/03 14:49:54 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mandelbrot(t_fcl *fcl, int x, int y)
{
	int		i;
	t_dot	z;
	t_dot	c;
	t_dot	old;

	i = 0;
	c.r = fcl->rat * (x - fcl->half_w) / fcl->zoom_w + fcl->x_move;
	c.i = (y - fcl->half_h) / fcl->zoom_h + fcl->y_move;
	z.r = 0.0;
	z.i = 0.0;
	while ((POW(z.r) + POW(z.i)) < 4 && ++i < fcl->max)
	{
		old = z;
		z.r = POW(old.r) - POW(old.i) + c.r;
		z.i = 2 * (old.r * old.i) + c.i;
	}
	return (i);
}

int		julia(t_fcl *fcl, int x, int y)
{
	int		i;
	t_dot	c;
	t_dot	z;
	t_dot	old;

	i = 0;
	c.r = fcl->rat * (x - fcl->half_w) / fcl->zoom_w + fcl->x_move;
	c.i = (y - fcl->half_h) / fcl->zoom_h + fcl->y_move;
	z.r = fcl->mx;
	z.i = fcl->my;
	while ((POW(c.r) + POW(c.i)) < 4 && ++i < fcl->max)
	{
		old = c;
		c.r = POW(old.r) - POW(old.i) + z.r;
		c.i = 2 * (old.r * old.i) + z.i;
	}
	return (i);
}

int		ship(t_fcl *fcl, int x, int y)
{
	int		i;
	t_dot	z;
	t_dot	c;
	double	old;

	i = 0;
	c.r = fcl->rat * (x - fcl->half_w) / fcl->zoom_w + fcl->x_move;
	c.i = (y - fcl->half_h) / fcl->zoom_h + fcl->y_move;
	z.r = c.r;
	z.i = c.i;
	while (POW(z.r) + POW(z.i) < 4 && ++i < fcl->max)
	{
		old = z.i;
		z.i = fabs((2 * (z.r * z.i) + c.i));
		z.r = fabs((POW(z.r) - POW(old) + c.r));
	}
	return (i);
}

int		newton(t_fcl *fcl, int x, int y)
{
	int		i;
	t_dot	z;
	t_dot	c;
	double	old;

	i = 0;
	old = 1.0;
	c.r = fcl->rat * (x - fcl->half_w) / fcl->zoom_w + fcl->x_move;
	c.i = (y - fcl->half_h) / fcl->zoom_h + fcl->y_move;
	z.r = c.r;
	z.i = c.i;
	while (old > 0.000001 && ++i < fcl->max)
	{
		z.r = c.r;
		z.i = c.i;
		old = ft_powd(POW(c.r) + POW(c.i), 2);
		c.r = (2 * z.r * old + POW(c.r) - POW(c.i)) / (3.0 * old);
		c.i = (2 * c.i * (old - z.r)) / (3.0 * old);
		old = ft_powd(c.r - z.r, 2) + ft_powd(c.i - z.i, 2);
	}
	return (i);
}

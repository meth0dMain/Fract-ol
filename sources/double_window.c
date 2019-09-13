/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:34:11 by ndremora          #+#    #+#             */
/*   Updated: 2019/06/03 14:49:54 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	win2(t_fcl *fcl, int x, int y, t_col *col)
{
	int i;

	pixel_to_img2(fcl, x, y, col);
	i = julia(fcl, x, y);
	color_func(i, fcl->count * 0.25, col);
	pixel_to_img3(fcl, x, y, col);
}

void	pixel_to_img2(t_fcl *fcl, int x, int y, t_col *c)
{
	int	index;

	index = x * 2 + fcl->size_line * y;
	fcl->image_data[index] = c->red;
	fcl->image_data[index + 1] = c->green;
	fcl->image_data[index + 2] = c->blue;
}

void	pixel_to_img3(t_fcl *fcl, int x, int y, t_col *c)
{
	int	index;

	index = (x + WIDTH) * 2 + fcl->size_line * y;
	fcl->image_data[index] = c->red;
	fcl->image_data[index + 1] = c->green;
	fcl->image_data[index + 2] = c->blue;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 10:40:35 by ndremora          #+#    #+#             */
/*   Updated: 2019/04/10 09:35:43 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	color_func(int i, double p, t_col *col)
{
	col->red = 255 * (pow(cos(sqrt(i) + p), 2));
	col->green = 255 * (pow(cos(sqrt(i) + p + 1), 2));
	col->blue = 255 * (pow(cos(sqrt(i) + p + 2), 2));
}

void	color_func2(int i, int max, t_col *col)
{
	double t;

	t = (double)i / (double)max;
	col->red = (int)(9 * (1 - t) * t * t * t * 255);
	col->green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	col->blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
}

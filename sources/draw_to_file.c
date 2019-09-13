/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_to_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:14:32 by ndremora          #+#    #+#             */
/*   Updated: 2019/04/16 12:05:08 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		draw2(t_fcl *fcl)
{
	char *filename;
	FILE *fp;

	fcl->zoom_w = 0.25 * fcl->zoom * WIDTH;
	fcl->zoom_h = 0.25 * fcl->zoom * HEIGHT;
	filename = "ndremora.fdf";
	fp = fopen(filename, "w+");
	fractal2(fcl, fp);
	fclose(fp);
	mlx_put_image_to_window(fcl->mlx, fcl->win, fcl->img, 0, 0);
/*	mlx_string_put(fcl->mlx, fcl->win, 10, 8, 0x777777, "zoom:");
	mlx_string_put(fcl->mlx, fcl->win, 70, 8, 0x777777, ft_itoa(fcl->zoom));
	mlx_string_put(fcl->mlx, fcl->win, 10, 25, 0x777777, "max:");
	mlx_string_put(fcl->mlx, fcl->win, 70, 25, 0x777777, ft_itoa(fcl->max));*/
	return (0);
}

void	fractal2(t_fcl *fcl, FILE *fp)
{
	int		x;
	int		y;
	int		i;
	t_col	c;

	y = -1;
	while (++y <= HEIGHT)
	{
		x = -1;
		while (++x <= WIDTH)
		{
			if (fcl->f == 2)
				i = julia(fcl, x, y);
			else if (fcl->f == 3)
				i = ship(fcl, x, y);
			else if (fcl->f == 4)
				i = newton(fcl, x, y);
			else
				i = mandelbrot(fcl, x, y);
			//color_func2(i, fcl->max, &c);
			color_func(i, fcl->count * 0.25, &c);
			add_to_map(&c, i, fp);
			(fcl->f == 5) ? (win2(fcl, x, y, &c)) : (pxl_to_i(fcl, x, y, &c));
		}
		fprintf(fp, "%s", "\n");
	}
}

void	asctohex(char a, char *s, int i)
{
	char c;

	c = (a >> 4) & 0x0f;
	if (c <= 9)
		c += '0';
	else
		c += 'a' - 10;
	s[i] = c;
	c = a & 0x0f;
	if (c <= 9)
		c += '0';
	else
		c += 'a' - 10;
	s[i + 1] = c;
}

void	add_to_map(t_col *col, int i, FILE *fp)
{
	char hex_color[9];

	hex_color[0] = '0';
	hex_color[1] = 'x';
	hex_color[8] = '\0';
	asctohex(col->red, hex_color, 2);
	asctohex(col->green, hex_color, 4);
	asctohex(col->blue, hex_color, 6);
	fprintf(fp, "%d,%s ", i, hex_color);
}

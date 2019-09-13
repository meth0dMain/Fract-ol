/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:42:57 by ndremora          #+#    #+#             */
/*   Updated: 2019/06/26 14:18:40 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		main(int ac, char **av)
{
	t_fcl	fcl;
	t_fcl	fcl2;

	if (ac != 2 && ac != 3)
		ft_error("Usage : ./fractol  param's must be: [mandelbrot],"\
		"[julia], [ship] or [newton]");
	check_usage(&fcl, av, 1);
	fractal_init(&fcl);
	draw(&fcl);
	if (ac == 3)
	{
		check_usage(&fcl2, av, 2);
		fractal_init2(&fcl2, &fcl);
		draw(&fcl2);
		mlx_hooks2(&fcl, &fcl2);
		return (0);
	}
	mlx_hooks(&fcl);
	return (0);
}

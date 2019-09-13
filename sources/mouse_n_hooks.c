/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:50:52 by ndremora          #+#    #+#             */
/*   Updated: 2019/06/03 14:49:54 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		deal_mouse(int key, int x, int y, t_fcl *fcl)
{
	(void)x;
	(void)y;
	if (key == 4)
	{
		fcl->zoom *= ft_powd(1.001, abs(++fcl->zoom_t));
		draw(fcl);
	}
	else if (key == 5)
	{
		fcl->zoom /= ft_powd(1.001, abs(--fcl->zoom_t));
		draw(fcl);
	}
	else if (key == 1)
		fcl->click++;
	return (0);
}

int		move_mouse(int x, int y, t_fcl *fcl)
{
	if (fcl->click % 2 == 0)
	{
		fcl->mx = fcl->rat * (x - fcl->half_w) / fcl->zoom_w + fcl->x_move;
		fcl->my = (y - fcl->half_h) / fcl->zoom_h + fcl->y_move;
		draw(fcl);
	}
	return (0);
}

void	mlx_hooks(t_fcl *fcl)
{
	mlx_hook(fcl->win, 2, 0, deal_key, fcl);
	mlx_hook(fcl->win, 17, 0, close_x, fcl);
	mlx_hook(fcl->win, 4, 5, deal_mouse, fcl);
	mlx_hook(fcl->win, 6, 5, move_mouse, fcl);
	mlx_loop(fcl->mlx);
}

void	mlx_hooks2(t_fcl *fcl, t_fcl *fcl2)
{
	mlx_hook(fcl->win, 2, 0, deal_key, fcl);
	mlx_hook(fcl2->win, 2, 0, deal_key, fcl2);
	mlx_hook(fcl->win, 17, 0, close_x, fcl);
	mlx_hook(fcl2->win, 17, 0, close_x, fcl2);
	mlx_hook(fcl->win, 4, 5, deal_mouse, fcl);
	mlx_hook(fcl2->win, 4, 5, deal_mouse, fcl2);
	mlx_hook(fcl->win, 6, 5, move_mouse, fcl);
	mlx_hook(fcl2->win, 6, 5, move_mouse, fcl2);
	mlx_loop(fcl->mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:51:14 by ndremora          #+#    #+#             */
/*   Updated: 2019/06/03 14:49:54 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	move(int key, t_fcl *fcl)
{
	if (key == KEY_LEFT)
		fcl->x_move -= 0.001 * abs(fcl->zoom_t) / fcl->zoom;
	else if (key == KEY_RIGHT)
		fcl->x_move += 0.001 * abs(fcl->zoom_t) / fcl->zoom;
	else if (key == KEY_UP)
		fcl->y_move -= 0.001 * abs(fcl->zoom_t) / fcl->zoom;
	else
		fcl->y_move += 0.001 * abs(fcl->zoom_t) / fcl->zoom;
	draw(fcl);
}

void	zoom(int key, t_fcl *fcl)
{
	if (key == KEY_PAD_ADD && fcl->zoom < 1000000000)
		fcl->zoom *= pow(1.001, abs(++fcl->zoom_t));
	else if (key == KEY_PAD_SUB && fcl->zoom > 0)
		fcl->zoom /= pow(1.001, abs(--fcl->zoom_t));
	draw(fcl);
}

void	change_max(int key, t_fcl *fcl)
{
	if (key == KEY_EQUAL && fcl->max <= 300)
		fcl->max += 10;
	else if (key == KEY_MINUS && fcl->zoom > 0)
		fcl->max = (fcl->max <= 10) ? 10 : fcl->max - 10;
	draw(fcl);

}

int		close_x(void *param)
{
	(void)param;
	ft_error("X button pressed.");
	exit(0);
}

int		deal_key(int key, t_fcl *fcl)
{
	if (key == KEY_ESCAPE)
	{
		ft_error("Escape pressed.");
	}
	else if (key >= KEY_LEFT && key <= KEY_UP)
		move(key, fcl);
	else if (key == KEY_PAD_ADD || key == KEY_PAD_SUB)
		zoom(key, fcl);
	else if (key == KEY_EQUAL || key == KEY_MINUS)
		change_max(key, fcl);
	else if (key == KEY_TAB)
	{
		fcl->count++;
		draw(fcl);
	}
	else if (key == KEY_ENTER)
		draw2(fcl);
	else if (key == KEY_C)
	{
		fcl->cross++;
		draw(fcl);
	}
	return (0);
}

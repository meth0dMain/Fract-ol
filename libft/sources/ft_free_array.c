/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:46:37 by ndremora          #+#    #+#             */
/*   Updated: 2019/06/03 14:49:54 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
		ft_strdel(&array[i++]);
	free(array);
	array = NULL;
}

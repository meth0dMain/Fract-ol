/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:35:20 by ndremora          #+#    #+#             */
/*   Updated: 2019/04/12 10:40:01 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int				i;
	long long int	nb;
	long			isneg;

	i = 0;
	nb = 0;
	isneg = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			isneg = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (nb != (nb * 10) / 10)
		{
			nb = (isneg > 0 ? 0 : -1);
			return (nb);
		}
		nb = 10 * nb + (str[i++] - '0');
	}
	return (isneg == 1 ? -nb : nb);
}

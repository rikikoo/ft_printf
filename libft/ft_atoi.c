/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:29:58 by rkyttala          #+#    #+#             */
/*   Updated: 2020/08/07 19:09:16 by rikikyttala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 1;
	if (!str)
		return (0);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || \
str[i] == '\r' || str[i] == '\f' || str[i] == '\v' || str[i] == '0')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = 1 - (2 * (str[i] == '-'));
		i++;
	}
	while (str[i] != '\0' && (str[i] > 47 && str[i] < 58))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}

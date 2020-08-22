/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikikytt <rikikytt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 18:26:28 by rikikytt          #+#    #+#             */
/*   Updated: 2020/08/15 18:32:22 by rikikyttala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr(char *str, int n)
{
	int		i;

	i = 0;
	if (!str)
		return ;
	while (i < n && str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

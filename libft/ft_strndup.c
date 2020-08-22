/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikikytt <rikikytt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:35:01 by rikikytt          #+#    #+#             */
/*   Updated: 2020/08/13 15:39:30 by rikikyttala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int len)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = (char*)malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (0);
	while (s1[i] != '\0' && i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 21:29:44 by rkyttala          #+#    #+#             */
/*   Updated: 2020/08/30 22:55:53 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_free(char *s1)
{
	int		len;
	char	*s2;

	len = 0;
	while (s1[len] != '\0')
		len++;
	if (!(s2 = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	len = 0;
	while (s1[len] != '\0')
	{
		s2[len] = s1[len];
		len++;
	}
	s2[len] = '\0';
	free(s1);
	s1 = NULL;
	return (s2);
}
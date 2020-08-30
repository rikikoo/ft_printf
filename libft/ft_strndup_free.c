/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 21:33:10 by rkyttala          #+#    #+#             */
/*   Updated: 2020/08/30 21:34:15 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup_free(char *s1, int len)
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
	free(s1);
	s1 = NULL;
	return (s2);
}

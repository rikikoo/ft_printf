/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 19:26:37 by rkyttala          #+#    #+#             */
/*   Updated: 2020/08/30 21:46:39 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(const char *s1, char *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*str;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if ((str = (char*)malloc(sizeof(char) * (len1 + len2 + 1))) == NULL)
		return (0);
	i = -1;
	while (s1[++i] != '\0')
		str[i] = s1[i];
	i = 0;
	while (s2[i] != '\0')
		str[len1++] = s2[i++];
	str[len1] = '\0';
	free(s2);
	s2 = NULL;
	return (str);
}

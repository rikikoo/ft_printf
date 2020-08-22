/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 11:30:44 by rkyttala          #+#    #+#             */
/*   Updated: 2019/11/06 17:20:36 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*str;

	i = 0;
	len1 = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i++] != '\0')
		len1++;
	i = 0;
	len2 = 0;
	while (s2[i++] != '\0')
		len2++;
	if ((str = (char*)malloc(sizeof(char) * (len1 + len2 + 1))) == NULL)
		return (0);
	i = -1;
	while (s1[++i] != '\0')
		str[i] = s1[i];
	i = 0;
	while (s2[i] != '\0')
		str[len1++] = s2[i++];
	str[len1] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:21:53 by rkyttala          #+#    #+#             */
/*   Updated: 2020/08/30 23:09:39 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_liberator(int n, ...)
{
	va_list		ap;
	void		**ptr;

	va_start(ap, n);
	while (n)
	{
		ptr = va_arg(ap, void **);
		if (ptr != NULL)
		{
			free(*ptr);
			*ptr = NULL;
		}
		n--;
	}
	va_end(ap);
}

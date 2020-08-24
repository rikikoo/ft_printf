/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 17:04:02 by rkyttala          #+#    #+#             */
/*   Updated: 2020/08/24 16:56:45 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int				ret;
	unsigned long	n;

	n = 983724692;
	ret = ft_printf("%-.6lu\n", n);
	printf("%d\n\n", ret);
	ret = printf("%-.6lu\n", n);
	printf("%i\n", ret);
	return (0);
}

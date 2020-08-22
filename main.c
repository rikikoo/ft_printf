/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 17:04:02 by rkyttala          #+#    #+#             */
/*   Updated: 2020/08/22 19:59:47 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int				ret;
	unsigned long	n;

	n = 7654;
	ret = ft_printf("%-.6lu\n", n);
	printf("%d\n\n", ret);
	ret = printf("%-.6lu\n", n);
	printf("%i\n", ret);
	return (0);
}

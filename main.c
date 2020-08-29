/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 17:04:02 by rkyttala          #+#    #+#             */
/*   Updated: 2020/08/29 18:46:33 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int				ret;
	unsigned int	n;

	n = 4242;
	ret = ft_printf("@moulitest: %-5.o\n", 0);
	printf("%d\n\n", ret);
	ret = printf("@moulitest: %-5.o\n", 0);
	printf("%i\n", ret);
	return (0);
}

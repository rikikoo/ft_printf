/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 17:04:02 by rkyttala          #+#    #+#             */
/*   Updated: 2020/08/30 23:26:04 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int			ret;
	float		n;

	n = 349786.98765434567;
	ret = ft_printf("%.10f", n);
	printf("\n%d\n\n", ret);
//	while (1);
	ret = printf("%.10f", n);
	printf("\n%i\n", ret);
	return (0);
}

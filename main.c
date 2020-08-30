/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 17:04:02 by rkyttala          #+#    #+#             */
/*   Updated: 2020/08/30 19:00:40 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int				ret;
	unsigned int	n;

	n = 4242;
	ret = ft_printf("%f\t%lf\t%Lf", 1.42, 1.42, 1.42l);
	printf("\n%d\n\n", ret);
	ret = printf("%f\t%lf\t%Lf", 1.42, 1.42, 1.42l);
	printf("\n%i\n", ret);
	return (0);
}

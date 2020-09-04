/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 17:42:17 by rkyttala          #+#    #+#             */
/*   Updated: 2020/09/04 21:46:29 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include <stdio.h>

int		main()
{
	int		ret;
	double	p = -20.0;

	ret = ft_printf("'%08.2f'\n", p);
	printf("%d\n\n", ret);
	ret = printf("'%08.2f'\n", p);
	printf("%d\n", ret);

}

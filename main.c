/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 17:04:02 by rkyttala          #+#    #+#             */
/*   Updated: 2020/09/01 18:16:35 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int			ret;
/*
//	c
	ret = ft_printf("%hc\t%5hhc\t%.5lc\t%5.3llc", 'a', 'a', 'a', 'a');
	printf("\n%d\n", ret);
	ret = printf("%hc\t%5hhc\t%.5lc\t%5.3llc", 'a', 'a', 'a', 'a');
	printf("\n%d\n", ret);
	ret = ft_printf("%c\t%5c\t%.5c\t%5.3c", 0, NULL, 0, NULL);
	printf("\n%d\n\n", ret);
	ret = printf("%c\t%5c\t%.5c\t%5.3c", 0, NULL, 0, NULL);
	printf("\n%d\n\n", ret);
	printf("----------------------\n");
	printf("----------------------\n");

//	s
	ret = ft_printf("%s\t%5c\t%.5c\t%5.3c", "hi", "hi", "hi", "hi");
	printf("\n%d\n\n", ret);
	ret = printf("%s\t%5c\t%.5c\t%5.3c", "hi", "hi", "hi", "hi");
	printf("\n%d\n\n", ret);
	printf("----------------------\n");
	ret = ft_printf("%s\t%5c\t%.5c\t%5.3c", NULL, NULL, NULL, NULL);
	printf("\n%d\n\n", ret);
	ret = printf("%s\t%5c\t%.5c\t%5.3c", NULL, NULL, NULL, NULL);
	printf("\n%d\n\n", ret);
	printf("----------------------\n");
	ret = ft_printf("%s\t%-5c\t%.5c\t%-5.3c", "hi", "hi", "hi", "hi");
	printf("\n%d\n\n", ret);
	ret = printf("%s\t%-5c\t%.5c\t%-5.3c", "hi", "hi", "hi", "hi");
	printf("\n%d\n\n", ret);
	printf("----------------------\n");
	printf("----------------------\n");

//	p
	char	*ptr;
	ret = ft_printf("%p\t%5p\t%.5p\t%5.3p", &ptr, &ptr, &ptr, &ptr);
	printf("\n%d\n\n", ret);
	ret = printf("%p\t%5p\t%.5p\t%5.3p", &ptr, &ptr, &ptr, &ptr);
	printf("\n%d\n\n", ret);
	printf("----------------------\n");
	printf("----------------------\n");

//	d & i
	ret = ft_printf("%d\t%5i\t%.5d\t%5.3i", -42, 42, 42, -42);
	printf("\n%d\n\n", ret);
	ret = printf("%d\t%5i\t%.5d\t%5.3i", -42, 42, 42, -42);
	printf("\n%d\n\n", ret);
	printf("----------------------\n");
	ret = ft_printf("%d\t%-+5i\t%+.5d\t%-5.3i", -42, 42, 42, -42);
	printf("\n%d\n\n", ret);
	ret = printf("%d\t%-+5i\t%+.5d\t%-5.3i", -42, 42, 42, -42);
	printf("\n%d\n\n", ret);
	printf("----------------------\n");
	printf("----------------------\n");

//	o
	unsigned long	o_l = 42;
	unsigned long long	o_ll = 42;
	unsigned short	o_h = 42;
	unsigned int	o = 42;
	ret = ft_printf("%o\t%5lo\t%.5llo\t%5.3ho", o, o_l, o_ll, o_h);
	printf("\n%d\n\n", ret);
	ret = printf("%o\t%5lo\t%.5llo\t%5.3ho", o, o_l, o_ll, o_h);
	printf("\n%d\n\n", ret);
	printf("----------------------\n");
	ret = ft_printf("%#o\t%-5o\t%#.5o\t%#-5.3o", o, o, o, o);
	printf("\n%d\n\n", ret);
	ret = printf("%#o\t%-5o\t%#.5o\t%#-5.3o", o, o, o, o);
	printf("\n%d\n\n", ret);
	printf("----------------------\n");
	printf("----------------------\n");

//	u
	ret = ft_printf("%u\t%5u\t%.5u\t%-5.3u", o, o, o, o);
	printf("\n%d\n\n", ret);
	ret = printf("%u\t%5u\t%.5u\t%-5.3u", o, o, o, o);
	printf("\n%d\n\n", ret);
	printf("----------------------\n");
	ret = ft_printf("%u\t%5lu\t%.5llu\t%-5.3hu", o, o_l, o_ll, o_h);
	printf("\n%d\n\n", ret);
	ret = printf("%u\t%5lu\t%.5llu\t%-5.3hu", o, o_l, o_ll, o_h);
	printf("\n%d\n\n", ret);
	printf("----------------------\n");
	printf("----------------------\n");

//x
	ret = ft_printf("%x\t%5x\t%.5x\t%-5.3x", o, o, o, o);
	printf("\n%d\n\n", ret);
	ret = printf("%x\t%5x\t%.5x\t%-5.3x", o, o, o, o);
	printf("\n%d\n\n", ret);
	printf("----------------------\n");
	ret = ft_printf("%x\t%-5x\t%#.5x\t%#-5.3x", 0, o, o, o);
	printf("\n%d\n\n", ret);
	ret = printf("%x\t%-5x\t%#.5x\t%#-5.3x", 0, o, o, o);
	printf("\n%d\n\n", ret);
	printf("----------------------\n");
	ret = ft_printf("%X\t%5X\t%.5X\t%-5.3X", o, o, o, o);
	printf("\n%d\n\n", ret);
	ret = printf("%X\t%5X\t%.5X\t%-5.3X", o, o, o, o);
	printf("\n%d\n\n", ret);
	printf("----------------------\n");
	ret = ft_printf("%X\t%-5X\t%#.5X\t%#-5.3X", 0, o, o, o);
	printf("\n%d\n\n", ret);
	ret = printf("%X\t%-5X\t%#.5X\t%#-5.3X", 0, o, o, o);
	printf("\n%d\n\n", ret);
	printf("----------------------\n");
	printf("----------------------\n");
*/
//	f
	ret = ft_printf("%f\t%15f\t%.5f\t%-15.3f", 99.999, 0.9999999, 0.0, 2943.439876);
	printf("\n%d\n\n", ret);
	ret = printf("%f\t%15f\t%.5f\t%-15.3f", 99.999, 0.9999999, 0.0, 2943.439876);
	printf("\n%d\n\n", ret);
	printf("----------------------\n");
	ret = ft_printf("%010f\t%15f\t%+.5f\t% -15.f", 99.999, -0.13473, 0.0, 2943.439876);
	printf("\n%d\n\n", ret);
	ret = printf("%010f\t%15f\t%+.5f\t% -15.f", 99.999, -0.13473, 0.0, 2943.439876);
	printf("\n%d\n\n", ret);
	printf("----------------------\n");
	printf("----------------------\n");

	return (0);
}

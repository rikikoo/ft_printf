/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oux_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 19:32:40 by rkyttala          #+#    #+#             */
/*   Updated: 2020/08/22 19:36:02 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

unsigned long long		oux_length(t_specs *specs, va_list argp)
{
	unsigned long long	nb;

	if (specs->h)
		nb = (unsigned short)(va_arg(argp, unsigned int));
	else if (specs->hh)
		nb = (unsigned char)(va_arg(argp, unsigned int));
	else if (specs->l)
		nb = va_arg(argp, unsigned long);
	else if (specs->ll)
		nb = va_arg(argp, unsigned long long);
	else
		nb = va_arg(argp, unsigned int);
	if (!nb)
		exit(3);
	return (nb);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:01:38 by rkyttala          #+#    #+#             */
/*   Updated: 2020/08/21 14:57:37 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		f_output(t_specs *specs, char *str)
{

}

int		to_float(t_specs *specs, va_list argp)
{
	long double		nb;
	char			*str;

	if (specs->long_dbl)
		nb = va_arg(argp, long double);
	else
		nb = va_arg(argp, double);
	str = ft_ftoa(nb, specs->precision);
	return (f_output(specs, str));
}

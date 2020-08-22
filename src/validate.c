/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:24:22 by rkyttala          #+#    #+#             */
/*   Updated: 2020/08/22 12:20:40 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	validate_type(t_specs *specs)
{
	if (specs->plus && specs->space)
		specs->space = 0;
	if ((specs->minus || (specs->precision > 0 && !specs->dbl)) && specs->zero)
		specs->zero = 0;
	if (specs->character)
		return ('c');
	if (specs->string)
		return ('s');
	if (specs->pointer)
		return ('p');
	if (specs->integer)
		return ('i');
	if (specs->octal)
		return ('o');
	if (specs->uns)
		return ('u');
	if (specs->hex == 1)
		return ('x');
	if (specs->hex == 2)
		return ('X');
	if (specs->dbl)
		return ('f');
	return (0);
}

int		conv_bridge(t_specs *specs, va_list argp, char type)
{
	int		ret;

	ret = 0;
	if (type == 'c')
		ret = print_char(specs, argp);
	else if (type == 's')
		ret = prep_string(specs, argp);
	else if (type == 'p')
		ret = print_pointer(specs, argp);
	else if (type == 'i')
		ret = to_integer(specs, argp);
	else if (type == 'o')
		ret = to_octal(specs, argp);
	else if (type == 'u')
		ret = to_unsigned(specs, argp);
	else if (type == 'x')
		ret = to_hex(specs, argp, 0);
	else if (type == 'X')
		ret = to_hex(specs, argp, 1);
	else if (type == 'f')
		ret = to_float(specs, argp);
	return (ret);
}

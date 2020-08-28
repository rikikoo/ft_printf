/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 17:10:58 by rkyttala          #+#    #+#             */
/*   Updated: 2020/08/28 16:25:06 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	init_specs(t_specs *specs)
{
	specs->pound = 0;
	specs->zero = 0;
	specs->minus = 0;
	specs->plus = 0;
	specs->space = 0;
	specs->width = 0;
	specs->precision = -1;
	specs->type = 0;
	specs->l = 0;
	specs->ll = 0;
	specs->long_dbl = 0;
	specs->h = 0;
	specs->hh = 0;
}

int		spec_parse(char *format, t_specs *specs)
{
	int		i;

	init_specs(specs);
	i = 0;
	while (scan_flags(format[i], specs))
		i++;
	i += scan_width(format + i, specs);
	i += scan_precision(format + i, specs);
	i += scan_length(format + i, specs);
	scan_specifier(format[i], specs);
	validate_flags(specs);
	return (i + 1);
}

int		raw_parse(char *format, t_specs *specs, va_list argp)
{
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			i += spec_parse(format + i, specs);
			ret += conv_bridge(specs, argp, specs->type);
		}
		else
		{
			ft_putchar(format[i]);
			ret++;
			i++;
		}
	}
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list	argp;
	t_specs	*specs;
	int		ret;

	if (!format)
		return (-1);
	if (!(specs = (t_specs *)malloc(sizeof(t_specs))))
		exit(1);
	va_start(argp, format);
	ret = raw_parse((char *)format, specs, argp);
	va_end(argp);
	return (ret);
}

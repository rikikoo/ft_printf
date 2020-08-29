/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 22:29:59 by rkyttala          #+#    #+#             */
/*   Updated: 2020/08/29 18:34:52 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		x_output_l(t_specs *specs, char *str, int len, char *pref)
{
	int		ret;

	if (specs->precision == -1)
	{
		if (specs->pound)
			ft_putstr(pref);
		ft_putstr(str);
		ft_putpad(specs->width - (specs->pound ? len + 2 : len), ' ');
		ret = specs->width;
	}
	else
	{
		if (specs->pound)
			ft_putstr(pref);
		if (specs->precision > len)
			ft_putpad(specs->precision - len, '0');
		ft_putstr(str);
		ft_putpad((specs->pound ? specs->width - len - 2 \
			: specs->width - len), ' ');
		if (specs->width >= specs->precision + (specs->pound ? 2 : 0))
			ret = specs->width;
		else
			ret = specs->precision + (specs->pound ? 2 : 0);
	}
	return (ret);
}

int		x_output_r(t_specs *specs, char *str, int len, char *pref)
{
	int		ret;

	if (specs->zero && specs->precision == -1)
	{
		if (specs->pound)
			ft_putstr(pref);
		ft_putpad(specs->width - (specs->pound ? len + 2 : len), '0');
		ft_putstr(str);
		ret = specs->width;
	}
	else
	{
		ft_putpad(specs->pound ? specs->width - len - 2 \
			: specs->width - len, ' ');
		if (specs->pound)
			ft_putstr(pref);
		if (specs->precision > len)
			ft_putpad(specs->precision - len, '0');
		ft_putstr(str);
		if (specs->width >= specs->precision + (specs->pound ? 2 : 0))
			ret = specs->width;
		else
			ret = specs->precision + (specs->pound ? 2 : 0);
	}
	return (ret);
}

int		x_output(t_specs *specs, char *str, int len, char *pref)
{
	int		ret;

	if (specs->precision > len)
	{
		if (specs->pound)
			ft_putstr(pref);
		ft_putpad(specs->precision - len, '0');
		ft_putstr(str);
		ret = specs->precision + (specs->pound ? 2 : 0);
	}
	else
	{
		if (specs->pound)
			ft_putstr(pref);
		ft_putstr(str);
		if (specs->pound)
			ret = len + 2;
		else
			ret = len;
	}
	return (ret);
}

int		to_hex(t_specs *specs, va_list argp, int upper)
{
	unsigned long long	nb;
	int					len;
	char				*str;
	char				*prefix;

	if (!(nb = oux_length(specs, argp)))
		return (ox_zeroprecision(specs));
	prefix = ft_strdup("0x");
	if (upper)
	{
		str = ft_itoa_base(nb, 16, 1);
		prefix[1] = 'X';
	}
	else
		str = ft_itoa_base(nb, 16, 0);
	len = ft_strlen(str);
	if (specs->width > len && specs->width > specs->precision && !specs->minus)
		return (x_output_r(specs, str, len, prefix));
	if (specs->width > len && specs->width > specs->precision && specs->minus)
		return (x_output_l(specs, str, len, prefix));
	return (x_output(specs, str, len, prefix));
}

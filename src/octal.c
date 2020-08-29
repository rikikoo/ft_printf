/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 17:09:42 by rkyttala          #+#    #+#             */
/*   Updated: 2020/08/29 18:35:16 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		o_output_l(t_specs *specs, char *str, int len)
{
	if (len >= specs->width && len >= specs->precision)
	{
		ft_putstr(str);
		return (len);
	}
	if (specs->precision <= len)
		ft_putstr(str);
	else
	{
		ft_putpad(specs->precision - len, '0');
		ft_putstr(str);
		len = specs->precision;
	}
	if (specs->width > len)
		ft_putpad(specs->width - len, ' ');
	return (len >= specs->width ? len : specs->width);
}

int		o_output_r(t_specs *specs, char *str, int len)
{
	if (len >= specs->width && len >= specs->precision)
	{
		ft_putstr(str);
		return (len);
	}
	if (specs->width > specs->precision && specs->width > len)
		ft_putpad(specs->width - (len >= specs->precision ? \
			len : specs->precision), specs->zero ? '0' : ' ');
	if (specs->precision <= len)
		ft_putstr(str);
	else
	{
		ft_putpad(specs->precision - len, '0');
		ft_putstr(str);
		len = specs->precision;
	}
	return (len >= specs->width ? len : specs->width);
}

int		to_octal(t_specs *specs, va_list argp)
{
	unsigned long long	nb;
	int					len;
	char				*str;

	if (!(nb = oux_length(specs, argp)) && specs->precision == 0)
		return (ox_zeroprecision(specs));
	str = ft_itoa_base(nb, 8, 0);
	len = ft_strlen(str);
	if (specs->pound && specs->precision < len)
	{
		str = ft_strjoin("0", str);
		len++;
	}
	if (specs->minus)
		return (o_output_l(specs, str, len));
	else
		return (o_output_r(specs, str, len));
}

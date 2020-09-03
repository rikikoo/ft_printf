/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 17:09:42 by rkyttala          #+#    #+#             */
/*   Updated: 2020/09/03 12:34:27 by rkyttala         ###   ########.fr       */
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
	int					joined;
	char				*str;

	if (!(nb = oux_length(specs, argp)) && specs->precision == 0)
		return (oux_zeroprecision(specs));
	if (nb == 0)
		specs->pound = 0;
	str = ft_itoa_base(nb, 8, 0);
	len = ft_strlen(str);
	joined = 0;
	if (specs->pound && specs->precision < len)
	{
		str = ft_strjoin_free(ft_strdup("0"), str);
		len++;
		joined = 1;
	}
	if (specs->minus)
		len = o_output_l(specs, str, len);
	else
		len = o_output_r(specs, str, len);
	free(str);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 22:41:46 by rkyttala          #+#    #+#             */
/*   Updated: 2020/08/30 22:46:34 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		u_output(t_specs *specs, char *str, int len)
{
	if (specs->minus)
	{
		ft_putstr(str);
		if (specs->width > len)
			ft_putpad(specs->width - len, ' ');
		if (specs->width > len)
			return (specs->width);
		return (len);
	}
	if (specs->width > len)
	{
		ft_putpad(specs->width - len, specs->zero ? '0' : ' ');
		ft_putstr(str);
		return (specs->width);
	}
	ft_putstr(str);
	return (len);
}

int		to_unsigned(t_specs *specs, va_list argp)
{
	unsigned long long	nb;
	char				*tmp;
	char				*pad;
	char				*str;
	int					len;

	if (!(nb = oux_length(specs, argp)) && specs->precision == 0)
		return (oux_zeroprecision(specs));
	tmp = ft_itoa_base(nb, 10, 0);
	len = ft_strlen(tmp);
	if (specs->precision > len)
	{
		if (!(pad = ft_strnew(specs->precision - len)))
			exit(1);
		len = specs->precision - len;
		while (len--)
			pad[len] = '0';
		str = ft_strjoin(pad, tmp);
		ft_liberator(1, &pad);
		return (u_output(specs, str, ft_strlen(str)));
	}
	return (u_output(specs, tmp, ft_strlen(tmp)));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:01:38 by rkyttala          #+#    #+#             */
/*   Updated: 2020/08/22 18:50:55 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		f_output(t_specs *specs, char *str, char sign, int len)
{
	if (specs->plus || specs->space || sign == '-')
	{
		if (specs->plus && sign == '+')
			ft_putchar(sign);
		if (sign == '-')
			ft_putchar(sign);
		if (specs->space && sign == '+')
			ft_putchar(' ');
		len++;
	}
	if (specs->minus)
		ft_putstr(str);
	if (specs->width > len)
	{
		if (specs->zero)
			ft_putpad(specs->width - len, '0');
		else
			ft_putpad(specs->width - len, ' ');
		if (!specs->minus)
			ft_putstr(str);
		return (specs->width);
	}
	if (!specs->minus)
		ft_putstr(str);
	return (len);
}

int		to_float(t_specs *specs, va_list argp)
{
	long double		nb;
	char			*str;
	char			sign;

	if (specs->long_dbl)
		nb = va_arg(argp, long double);
	else
		nb = va_arg(argp, double);
	if (!nb)
		exit(3);
	str = ft_ftoa(nb, specs->precision);
	if (nb < 0)
	{
		sign = '-';
		str = ft_memmove(str, str + 1, ft_strlen(str));
	}
	else
		sign = '+';
	return (f_output(specs, str, sign, ft_strlen(str)));
}

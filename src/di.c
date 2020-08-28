/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 19:10:23 by rkyttala          #+#    #+#             */
/*   Updated: 2020/08/28 20:37:45 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		di_output_l(t_specs *specs, char *str, int len, char sign)
{
	if (specs->precision == -1)
	{
		if (is_signed(specs, sign))
			ft_putchar(sign);
		ft_putstr(str);
		ft_putpad(specs->width - (is_signed(specs, sign) ? len + 1 : len), ' ');
		return (specs->width);
	}
	if (is_signed(specs, sign))
		ft_putchar(sign);
	if (specs->precision > len)
		ft_putpad(specs->precision - len, '0');
	ft_putstr(str);
	if (specs->precision > len)
		len = specs->precision;
	ft_putpad((is_signed(specs, sign) ? specs->width - len - 1 \
		: specs->width - len), ' ');
	if (specs->width >= specs->precision + (is_signed(specs, sign) ? 1 : 0))
		return (specs->width);
	else
		return (specs->precision + (is_signed(specs, sign) ? 1 : 0));
}

int		di_output_r(t_specs *specs, char *str, int len, char sign)
{
	if (specs->zero && specs->precision == -1)
	{
		if (is_signed(specs, sign))
			ft_putchar(sign);
		ft_putpad(specs->width - (is_signed(specs, sign) ? len + 1 : len), '0');
		ft_putstr(str);
		return (specs->width);
	}
	if (specs->precision > len)
		ft_putpad(specs->width - (is_signed(specs, sign) ? specs->precision + 1\
		: specs->precision), ' ');
	else
		ft_putpad(is_signed(specs, sign) ? specs->width - len - 1 \
		: specs->width - len, ' ');
	if (is_signed(specs, sign))
		ft_putchar(sign);
	if (specs->precision > len)
		ft_putpad(specs->precision - len, '0');
	ft_putstr(str);
	if (specs->width >= specs->precision + (is_signed(specs, sign) ? 1 : 0))
		return (specs->width);
	else
		return (specs->precision + (is_signed(specs, sign) ? 1 : 0));
}

int		di_output(t_specs *specs, char *str, int len, char sign)
{
	int		ret;

	if (specs->precision > len)
	{
		if (is_signed(specs, sign))
			ft_putchar(sign);
		ft_putpad(specs->precision - len, '0');
		ft_putstr(str);
		ret = specs->precision + (is_signed(specs, sign) ? 1 : 0);
	}
	else
	{
		if (is_signed(specs, sign))
			ft_putchar(sign);
		ft_putstr(str);
		if (is_signed(specs, sign))
			ret = len + 1;
		else
			ret = len;
	}
	return (ret);
}

int		to_integer(t_specs *specs, va_list argp)
{
	long long int	nb;
	char			*str;
	char			sign;
	int				len;

	nb = di_length(specs, argp);
	sign = (nb < 0 ? '-' : '+');
	if (sign == '-')
		nb *= -1;
	if (specs->space && sign == '+')
		sign = ' ';
	str = ft_itoa_base(nb, 10, 0);
	len = ft_strlen(str);
	if (specs->width > len && specs->width > specs->precision && specs->minus)
		return (di_output_l(specs, str, len, sign));
	if (specs->width > len && specs->width > specs->precision && !specs->minus)
		return (di_output_r(specs, str, len, sign));
	return (di_output(specs, str, len, sign));
}
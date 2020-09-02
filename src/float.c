/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:01:38 by rkyttala          #+#    #+#             */
/*   Updated: 2020/09/01 19:23:14 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		f_output_l(t_specs *specs, char *str, char sign, int len)
{
	if (is_signed(specs, sign))
	{
		ft_putchar(sign);
		len++;
	}
	if (specs->width > len)
	{
		ft_putstr(str);
		ft_putpad(specs->width - len, ' ');
		return (specs->width);
	}
	ft_putstr(str);
	return (len);
}

int		f_output_r(t_specs *specs, char *str, char sign, int len)
{
	if (is_signed(specs, sign))
		len++;
	if (specs->width > len)
	{
		if (is_signed(specs, sign) && specs->zero)
			ft_putchar(sign);
		ft_putpad(specs->width - len, specs->zero ? '0' : ' ');
		if (is_signed(specs, sign) && !specs->zero)
			ft_putchar(sign);
		ft_putstr(str);
		return (specs->width);
	}
	if (is_signed(specs, sign))
		ft_putchar(sign);
	ft_putstr(str);
	return (len);
}

char	*f_zero(int precision)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * precision + 3)))
		exit(1);
	str[precision + 2] = '\0';
	while (i <= precision + 1)
	{
		str[i] = '0';
		i++;
	}
	str[1] = '.';
	return (str);
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
	if (nb == 0.0 && specs->precision > 0)
		str = f_zero(specs->precision);
	else
		str = ft_ftoa(nb, specs->precision);
	if (nb < 0)
	{
		sign = '-';
		str = ft_memmove(str, str + 1, ft_strlen(str));
	}
	else
		sign = specs->space ? ' ' : '+';
	if (specs->minus)
		return (f_output_l(specs, str, sign, ft_strlen(str)));
	else
		return (f_output_r(specs, str, sign, ft_strlen(str)));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 17:08:41 by rkyttala          #+#    #+#             */
/*   Updated: 2020/08/28 21:26:30 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		print_char(t_specs *specs, va_list argp)
{
	char	c;

	c = va_arg(argp, int);
	if (specs->width < 2)
	{
		ft_putchar(c);
		return (1);
	}
	else
	{
		if (specs->minus)
			ft_putchar(c);
		ft_putpad(specs->width - 1, ' ');
		if (!specs->minus)
			ft_putchar(c);
		return (specs->width);
	}
}

int		print_string(t_specs *specs, char *str, int len)
{
	if (specs->width > len)
	{
		if (specs->minus)
			ft_putnstr(str, len);
		ft_putpad(specs->width - len, ' ');
		if (!specs->minus)
			ft_putnstr(str, len);
		return (specs->width);
	}
	ft_putnstr(str, len);
	return (len);
}

int		prep_string(t_specs *specs, va_list argp)
{
	int		len;
	char	*str;

	str = va_arg(argp, char *);
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	len = ft_strlen(str);
	if (specs->precision >= 0 && specs->precision < len)
		return (print_string(specs, str, specs->precision));
	else
		return (print_string(specs, str, len));
}

int		print_pointer(t_specs *specs, va_list argp)
{
	unsigned long long		ptr;
	int						len;

	if (!(ptr = (unsigned long long)(va_arg(argp, void *))))
		exit(3);
	len = ft_strlen(ft_itoa_base(ptr, 16, 0));
	if (len >= specs->width)
	{
		ft_putstr("0x");
		ft_putstr(ft_itoa_base(ptr, 16, 0));
		return (len + 2);
	}
	if (specs->minus)
	{
		ft_putstr("0x");
		ft_putstr(ft_itoa_base(ptr, 16, 0));
	}
	ft_putpad(specs->width - len - 2, ' ');
	if (!specs->minus)
	{
		ft_putstr("0x");
		ft_putstr(ft_itoa_base(ptr, 16, 0));
	}
	return (specs->width);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 17:08:41 by rkyttala          #+#    #+#             */
/*   Updated: 2020/08/19 00:20:42 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		print_char(t_specs *specs, va_list argp)
{
	int		i;

	i = 0;
	if (specs->width < 2)
	{
		ft_putchar(va_arg(argp, int));
		return (1);
	}
	else
	{
		if (specs->minus)
			ft_putchar(va_arg(argp, int));
		while (i < specs->width - 1)
		{
			ft_putchar(' ');
			i++;
		}
		if (!specs->minus)
			ft_putchar(va_arg(argp, int));
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

	if (!(str = va_arg(argp, char *)))
		exit(1); /* error: empty argument */
	len = ft_strlen(str);
	if (specs->precision > 0 && specs->precision < len)
		return (print_string(specs, str, specs->precision));
	else
		return (print_string(specs, str, len));
}

int		print_pointer(t_specs *specs, va_list argp)
{
	unsigned long long		ptr;
	int						len;

	ptr = (unsigned long long)(va_arg(argp, void *));
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

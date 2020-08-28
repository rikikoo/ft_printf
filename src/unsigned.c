/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 22:41:46 by rkyttala          #+#    #+#             */
/*   Updated: 2020/08/28 21:13:24 by rkyttala         ###   ########.fr       */
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
	char				*str;
	char				*pad;
	int					len;

	nb = oux_length(specs, argp);
	str = ft_itoa_base(nb, 10, 0);
	len = ft_strlen(str);
	if (specs->precision > len)
	{
		if (!(pad = (char *)malloc(sizeof(char) * specs->precision - len + 1)))
			exit(1);
		len = specs->precision - len;
		pad[len] = '\0';
		while (len--)
			pad[len] = '0';
		str = ft_strjoin(pad, str);
		free(pad);
		pad = NULL;
	}
	return (u_output(specs, str, ft_strlen(str)));
}

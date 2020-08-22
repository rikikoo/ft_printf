/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 22:29:59 by rkyttala          #+#    #+#             */
/*   Updated: 2020/08/22 19:36:51 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*add_prefix(t_specs *specs, char *str, int cap)
{
	int		len;
	int		i;
	char	*pad;

	len = ft_strlen(str);
	i = -1;
	if (specs->precision > len)
	{
		if (!(pad = (char *)malloc(sizeof(char) * specs->precision - len + 3)))
			exit(1);
		pad[specs->precision] = '\0';
		while (++i < specs->precision)
			pad[i] = '0';
		if (cap && specs->pound)
			pad[1] = 'X';
		else if (!cap && specs->pound)
			pad[1] = 'x';
		return (ft_strjoin(pad, str));
	}
	if (cap && specs->pound)
		return (ft_strjoin("0X", str));
	return (ft_strjoin("0x", str));
}

int		to_hex(t_specs *specs, va_list argp, int cap)
{
	unsigned long long	nb;
	int					len;
	char				*str;

	nb = oux_length(specs, argp);
	if (cap)
		str = ft_itoa_base(nb, 16, 1);
	else
		str = ft_itoa_base(nb, 16, 0);
	if (specs->pound || specs->precision)
		str = add_prefix(specs, str, cap);
	len = ft_strlen(str);
	if (specs->minus)
		ft_putstr(str);
	if (specs->width > len)
	{
		ft_putpad(specs->width - len, ' ');
		if (!specs->minus)
			ft_putstr(str);
		return (specs->width);
	}
	if (!specs->minus)
		ft_putstr(str);
	return (len);
}

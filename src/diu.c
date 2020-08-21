/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 16:25:57 by rkyttala          #+#    #+#             */
/*   Updated: 2020/08/19 15:25:16 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		diu_output(t_specs *specs, char *str, int len)
{
	if (specs->width > len)
	{
		if (specs->minus)
			ft_putstr(str);
		if (specs->zero)
			ft_putpad(specs->width - len, '0');
		else
			ft_putpad(specs->width - len, ' ');
		if (!specs->minus)
			ft_putstr(str);
		return (specs->width);
	}
	else
	{
		ft_putstr(str);
		return (len);
	}
}

char	*diu_format(t_specs *specs, unsigned long long nb, char sign)
{
	char	*str;
	char	*pad;
	int		len;

	str = ft_itoa_base(nb, 10, 0);
	len = ft_strlen(str);
	len = specs->precision > len ? specs->precision - len : 0;
	if (specs->plus || sign == '-' || specs->space)
		len++;
	if (!(pad = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	pad[len] = '\0';
	while (--len > 0)
		pad[len] = '0';
	if (specs->plus || sign == '-')
		pad[len] = sign;
	else
		pad[len] = ' ';
	return (ft_strjoin(pad, str));
}

int		to_integer(t_specs *specs, va_list argp)
{
	long long int	nb;
	char			*str;
	char			sign;

	if (specs->h)
		nb = (short)(va_arg(argp, int));
	else if (specs->hh)
		nb = (char)(va_arg(argp, int));
	else if (specs->l)
		nb = va_arg(argp, long);
	else if (specs->ll)
		nb = va_arg(argp, long long);
	else
		nb = va_arg(argp, int);
	sign = nb < 0 ? '-' : '+';
	if (sign == '-')
		nb *= -1;
	str = diu_format(specs, nb, sign);
	return (diu_output(specs, str, ft_strlen(str)));
}

int		to_unsigned(t_specs *specs, va_list argp)
{
	unsigned long long	nb;
	char				*str;

	if (specs->h)
		nb = (unsigned short)(va_arg(argp, unsigned int));
	else if (specs->hh)
		nb = (unsigned char)(va_arg(argp, unsigned int));
	else if (specs->l)
		nb = va_arg(argp, unsigned long);
	else if (specs->ll)
		nb = va_arg(argp, unsigned long long);
	else
		nb = va_arg(argp, unsigned int);
	str = (diu_format(specs, nb, '+'));
	return (diu_output(specs, str, ft_strlen(str)));
}

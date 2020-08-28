/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 19:32:40 by rkyttala          #+#    #+#             */
/*   Updated: 2020/08/28 19:35:16 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

unsigned long long		oux_length(t_specs *specs, va_list argp)
{
	unsigned long long	nb;

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
	return (nb);
}

long long				di_length(t_specs *specs, va_list argp)
{
	long long int	nb;

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
	return (nb);
}

int		is_signed(t_specs *specs, char sign)
{
	return (specs->plus || sign == ' ' || sign == '-');
}

int						print_percent(t_specs *specs)
{
	if (specs->width > 1)
	{
		if (specs->minus)
			ft_putchar('%');
		ft_putpad(specs->width - 1, specs->zero ? '0' : ' ');
		if (!specs->minus)
			ft_putchar('%');
		return (specs->width);
	}
	ft_putchar('%');
	return (1);
}

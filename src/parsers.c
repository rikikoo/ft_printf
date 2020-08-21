/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 18:36:06 by rkyttala          #+#    #+#             */
/*   Updated: 2020/08/19 00:11:20 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		scan_flags(char c, t_specs *specs)
{
	if (c == '%')
	{
		ft_putchar(c);
		specs->percent = 1;
		return (0);
	}
	else if (c == '#')
		specs->pound += 1;
	else if (c == '0')
		specs->zero += 1;
	else if (c == '-')
		specs->minus += 1;
	else if (c == '+')
		specs->plus += 1;
	else if (c == ' ')
		specs->space += 1;
	else
		return (0);
	return (1);
}

int		scan_width(char *format, t_specs *specs)
{
	char	*width;
	int		i;

	i = 0;
	while (ft_isdigit(format[i]))
		i++;
	if (i > 0)
	{
		if (!(width = (char *)malloc(sizeof(char) * i + 1)))
			return (0);
		width[i] = '\0';
		i = 0;
		while (ft_isdigit(format[i]))
		{
			width[i] = format[i];
			i++;
		}
		if (i > 0)
			specs->width += ft_atoi(width);
		free(width);
		width = NULL;
	}
	return (i);
}

int		scan_precision(char *format, t_specs *specs)
{
	int		i;
	char	*prec;

	i = 0;
	if (format[i] == '.')
	{
		while (ft_isdigit(format[i + 1]))
			i++;
		if (i > 0)
		{
			if (!(prec = (char *)malloc(sizeof(char) * i + 1)))
				return (0); /* error: malloc error */
			prec[i] = '\0';
			i = 1;
			while (ft_isdigit(format[i]))
			{
				prec[i - 1] = format[i];
				i++;
			}
			specs->precision = ft_atoi(prec);
			free(prec);
			prec = NULL;
		}
	}
	return (i);
}

int		scan_length(char *format, t_specs *specs)
{
	if (format[0] == 'h')
	{
		if (format[1] == 'h')
		{
			specs->hh = 1;
			return (2);
		}
		specs->h = 1;
	}
	else if (format[0] == 'l')
	{
		if (format[1] == 'l')
		{
			specs->ll = 1;
			return (2);
		}
		specs->l = 1;
	}
	else if (format[0] == 'L')
		specs->long_dbl = 1;
	else
		return (0);
	return (1);
}

void	scan_specifier(char c, t_specs *specs)
{
	if (c == 'c')
		specs->character = 1;
	else if (c == 's')
		specs->string = 1;
	else if (c == 'p')
		specs->pointer = 1;
	else if (c == 'f')
		specs->dbl = 1;
	else if (c == 'i' || c == 'd')
		specs->integer = 1;
	else if (c == 'o')
		specs->octal = 1;
	else if (c == 'u')
		specs->uns = 1;
	else if (c == 'x')
		specs->hex = 1;
	else if (c == 'X')
		specs->hex = 2;
	else
		exit(1); /* directs to error: unknown format specifier */
}

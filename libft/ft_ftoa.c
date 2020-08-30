/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 23:36:35 by rkyttala          #+#    #+#             */
/*   Updated: 2020/08/30 19:35:03 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*f_roundup(char *str, int i)
{
	if (i >= 0 && str[i + 1] >= '5')
	{
		if (str[i] != '9')
			str[i] = str[i] + 1;
		else
		{
			while (i - 1 >= 0)
			{
				str[i] = '0';
				if (str[i - 1] != '9')
				{
					str[i - 1] = str[i - 1] + 1;
					break ;
				}
				i--;
			}
		}
	}
	if (i == 0)
		str = ft_itoa_base((ft_atoll(str) + 1), 10, 0);
	return (str);
}

static char		*format_decimals(char *decimals)
{
	int		len;

	len = ft_strlen(decimals) - 1;
	while (len > 0)
	{
		decimals[len] = decimals[len - 1];
		len--;
	}
	decimals[0] = '.';
	return (decimals);
}

static char		*split_n_join(long double nb, int prec, int int_count)
{
	char		*str;
	char		*ints;
	char		*decimals;
	long long	n;

	n = (long long)nb;
	if (prec == 0)
		return (ft_itoa_base(n, 10, 0));
	prec = prec < 0 ? 7 : prec + 1;
	if (!(str = (char *)malloc(sizeof(char) * prec + 1)))
		return (0);
	str[prec] = '\0';
	while (prec != 0)
	{
		nb *= 10.0;
		prec--;
	}
	n = (long long)nb;
	str = ft_itoa_base(n, 10, 0);
	str = f_roundup(str, ft_strlen(str) - 2);
	ints = ft_strndup(str, int_count);
	decimals = format_decimals(ft_strdup(str + int_count));
	str = ft_strjoin(ints, decimals);
	return (str);
}

char			*ft_ftoa(long double nb, int precision)
{
	char			sign;
	char			*str;
	long double		tmp;
	int				int_count;

	sign = nb < 0 ? '-' : '+';
	tmp = nb;
	if (sign == '-')
	{
		nb *= -1.0;
		tmp *= -1.0;
	}
	int_count = 1;
	while (tmp >= 10.0)
	{
		tmp /= 10.0;
		int_count++;
	}
	str = split_n_join(nb, precision, int_count);
	return (sign == '-' ? ft_strjoin("-", str) : str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 23:36:35 by rkyttala          #+#    #+#             */
/*   Updated: 2020/09/01 18:25:18 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	- Takes a float value that has been turned into a sequence of numbers,
**	  represented as characters in a string and the amount of decimals.
**	- Returns a string that has been rounded up, as if the string was
**	  originally an integer.
*/
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

/*
**	- Takes a char pointer that points to the first decimal number character
**	- Moves all elements forward by 1 and places a decimal point to the start
**	- Returns the newly formatted decimal part
*/
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

/*
**	param1: original float value
**	param2: desired precision
**	param3: amount of numbers on the left side of the decimal point
**	param4: 1 (true) if original float value is < 1.0, otherwise 0 (false)
**
**	- turns all the digits of the float to one sequence of numbers
**	- sends that sequence as a string on for rounding up
**	- splits the rounded up string to whole & decimal number strings
**	  based on the given integer count
**	- joins them together, formatted properly and returns it
*/
static char		*split_n_join(long double nb, int prec, int int_count, int olt1)
{
	char				*str;
	char				*tmp;
	char				*ints;
	char				*decimals;
	int					orig_prec;

	orig_prec = prec;
	prec = prec < 0 ? 7 : prec + 1;
	while (prec != 0)
	{
		nb *= 10.0;
		prec--;
	}
	str = ft_itoa_base((unsigned long long)nb, 10, 0);
	tmp = f_roundup(str, ft_strlen(str) - 2);
	if (olt1)
		tmp[0] = tmp[0] - 1;
	ints = ft_strndup(tmp, int_count);
	decimals = format_decimals(ft_strdup(tmp + int_count));
	str = ft_strjoin(ints, decimals);
	if (orig_prec == 0)
		return (ints);
	return (str);
}

/*
**	ft_ftoa takes a float and returns its value with the desired precision
**	as a string.
**
**	This first function
**	- temporarily gets rid of the sign (if negative),
**	- counts the amount of integers
**	- sends that data onward for further processing,
**	- attaches the possible negative sign and
**	- returns the processed (rounded up) string.
*/
char			*ft_ftoa(long double nb, int precision)
{
	char			sign;
	char			*str;
	long double		tmp;
	int				int_count;

	sign = nb < 0 ? '-' : '+';
	if (sign == '-')
		nb *= -1.0;
	tmp = nb;
	int_count = 1;
	while (tmp >= 10.0)
	{
		tmp /= 10.0;
		int_count++;
	}
	if (nb < 1.0)
	{
		nb = nb + 1.0;
		str = split_n_join(nb, precision, int_count, 1);
	}
	else
		str = split_n_join(nb, precision, int_count, 0);
	return (sign == '-' ? ft_strjoin("-", str) : str);
}

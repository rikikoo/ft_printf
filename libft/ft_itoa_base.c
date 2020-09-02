/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikikytt <rikikytt@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 21:26:10 by rikikytt          #+#    #+#             */
/*   Updated: 2020/09/01 20:27:17 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*convert_base(unsigned long long n, int base, int len, int cap)
{
	unsigned long long	tmp;
	char				*nb;
	char				*str;
	char				*ret;

	tmp = n;
	nb = "0123456789abcdef";
	if (!(str = (char *)malloc(sizeof(char) * len) + 1))
		return (0);
	str[len] = '\0';
	len--;
	while (n > 0 && len >= 0)
	{
		tmp = n % base;
		n = n / base;
		if (cap > 0 && tmp >= 10)
			str[len] = nb[tmp] - 32;
		else
			str[len] = nb[tmp];
		len--;
	}
	ret = str;
	return (ret);
}

char			*ft_itoa_base(unsigned long long n, int base, int cap)
{
	int						len;
	unsigned long long		tmp;

	len = 0;
	tmp = n;
	if (n == 0)
		return ("0");
	if (base < 2 || base > 16)
		return (0);
	while (tmp > 0)
	{
		tmp = tmp / base;
		len++;
	}
	return (convert_base(n, base, len, cap));
}

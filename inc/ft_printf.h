/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyttala <rkyttala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 13:57:22 by rkyttala          #+#    #+#             */
/*   Updated: 2020/08/19 17:01:04 by rkyttala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_specs
{
	int		percent;
	int		space;
	int		pound;
	int		zero;
	int		minus;
	int		plus;
	int		width;
	int		precision;
	int		character;
	int		string;
	int		pointer;
	int		dbl;
	int		integer;
	int		octal;
	int		uns;
	int		hex;
	int		l;
	int		ll;
	int		long_dbl;
	int		h;
	int		hh;
}				t_specs;

int				main(void);
int				ft_printf(const char *format, ...);
int				raw_parse(char *format, t_specs *specs, va_list argp);
int				spec_parse(char *format, t_specs *specs);
void			init_specs(t_specs *specs);
int				scan_flags(char c, t_specs *specs);
int				scan_width(char *format, t_specs *specs);
int				scan_precision(char *format, t_specs *specs);
int				scan_length(char *format, t_specs *specs);
void			scan_specifier(char c, t_specs *specs);
char			validate_type(t_specs *specs);
int				conv_bridge(t_specs *specs, va_list argp, char type);
int				print_char(t_specs *specs, va_list argp);
int				prep_string(t_specs *specs, va_list argp);
int				print_string(t_specs *specs, char *str, int len);
int				print_pointer(t_specs *specs, va_list argp);
int				to_integer(t_specs *specs, va_list argp);
int				to_unsigned(t_specs *specs, va_list argp);
char			*diu_format(t_specs *specs, unsigned long long nb, char sign);
int				diu_output(t_specs *specs, char *str, int len);
int				to_octal(t_specs *specs, va_list argp);
int				o_output_left(t_specs *specs, char *str, int len);
int				o_output_right(t_specs *specs, char *str, int len);
int				to_hex(t_specs *specs, va_list argp, int cap);
char			*add_prefix(t_specs *specs, char *str, int cap);
int				to_float(t_specs *specs, va_list argp);
#endif

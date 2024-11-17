/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:12:48 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/17 03:39:52 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <float.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		plus;
	int		space;
	int		hash;
}	t_flags;

typedef struct s_printf
{
	va_list	ap;
	int		len;
	t_flags	flags;
	int		width;
	int		precision;
}	t_printf;

typedef struct s_format_data
{
	long long	num;
	char		*str;
	const char	*prefix;
	int			len;
	int			num_len;
}	t_format_data;

// Function prototypes
int		ft_printf(const char *format, ...);
void	x_char(t_printf *p);
void	x_str(t_printf *p);
void	x_ptr(t_printf *p);
void	x_int(t_printf *p);
void	x_uint(t_printf *p);
void	x_hex(t_printf *p, char c);
void	x_mod(t_printf *p);
void	ft_x(t_printf *p, char specifier);
void	ft_parse_format(t_printf *p, const char **format);

void	x_prefix(t_printf *p, const char *prefix);
void	x_number(t_printf *p, const char *str);
void	x_padding(t_printf *p, int len, char pad_char);
void	x_precision(t_printf *p, int num_len);

void	x_hex_get_base(char c, const char **base);
void	x_hex_get_prefix(char c, const char **prefix);
void	x_hex_pad_zero(t_printf *p, const char *prefix, int content_len);
void	x_hex_pad_space(t_printf *p, const char *prefix,
			int content_len, int num_len);
void	x_hex_get_pad(t_printf *p, char *pad_char);
void	x_hex_content_len(int *content_len, int precision,
			int num_len, int prefix_len);

void	x_int_init(t_printf *p, long long *num, const char **prefix);
void	x_int_zero(t_printf *p, const char *prefix, int len);
void	x_int_prefix(long long *num, const char **prefix, t_printf *p);
void	x_int_left(t_printf *p, char *str, const char *prefix,
			int len, int num_len);
void	x_int_right(t_printf *p, char *str, const char *prefix,
			int len, int num_len);

void	x_int_pad_zero(t_printf *p, const char *prefix, int len);
void	x_int_pad_space(t_printf *p, const char *prefix, int len, int num_len);
void	x_int_get_pad(t_printf *p, char *pad_char);

void	x_uint_init(t_printf *p, unsigned int *num);
void	x_uint_get_total_len(int *total_len, int precision, int num_len);
void	x_uint_left(t_printf *p, char *str, int total_len, int num_len);
void	x_uint_get_pad(t_printf *p, char *pad_char);
void	x_uint_right(t_printf *p, char *str, int total_len, int num_len);

#endif // FT_PRINTF_H

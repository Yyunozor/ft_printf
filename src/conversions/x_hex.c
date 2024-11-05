/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_hex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:42:27 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/05 15:47:50 by anpayot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*get_hex_prefix(char c, t_printf *p, unsigned long long num)
{
	if (p->flags.hash && num != 0)
	{
		if (c == 'x')
			return ("0x");
		else
			return ("0X");
	}
	return ("");
}

static char	*convert_to_hex_str(unsigned long long num, char c)
{
	if (c == 'x')
		return (ft_utoa_base(num, "0123456789abcdef"));
	else
		return (ft_utoa_base(num, "0123456789ABCDEF"));
}

static int	calculate_output_len(t_printf *p, const char *prefix, const char *hex_str)
{
	int	len;

	len = ft_strlen(prefix) + ft_strlen(hex_str);
	if (p->precision > (int)ft_strlen(hex_str))
		len += (p->precision - (int)ft_strlen(hex_str));
	return (len);
}

static void	write_left_aligned(t_printf *p, const char *prefix, const char *hex_str, int output_len)
{
	int	i;

	p->len += write(1, prefix, ft_strlen(prefix));
	i = 0;
	while (i < p->precision - (int)ft_strlen(hex_str))
	{
		p->len += write(1, "0", 1);
		i++;
	}
	p->len += write(1, hex_str, ft_strlen(hex_str));
	while (output_len < p->width)
	{
		p->len += write(1, " ", 1);
		output_len++;
	}
}

static void	write_padded(t_printf *p, const char *prefix, const char *hex_str, int output_len)
{
	char pad_char;
	int prefix_len;
	int i;

	if (p->flags.zero && p->precision == -1)
		pad_char = '0';
	else
		pad_char = ' ';
	prefix_len = ft_strlen(prefix);
	while (output_len < p->width && pad_char == ' ')
	{
		p->len += write(1, " ", 1);
		output_len++;
	}
	p->len += write(1, prefix, prefix_len);
	while (output_len < p->width && pad_char == '0')
	{
		p->len += write(1, "0", 1);
		output_len++;
	}
	i = 0;
	while (i < p->precision - (int)ft_strlen(hex_str))
	{
		p->len += write(1, "0", 1);
		i++;
	}
	p->len += write(1, hex_str, ft_strlen(hex_str));
}

void	x_hex(t_printf *p, char c)
{
	unsigned long long	num;
	const char			*prefix;
	char				*hex_str;
	int					output_len;

	if (c == 'x' || c == 'X')
		num = va_arg(p->ap, unsigned int);
	else
		num = va_arg(p->ap, unsigned long long);
	prefix = get_hex_prefix(c, p, num);
	hex_str = convert_to_hex_str(num, c);
	output_len = calculate_output_len(p, prefix, hex_str);
	if (p->flags.minus)
		write_left_aligned(p, prefix, hex_str, output_len);
	else
		write_padded(p, prefix, hex_str, output_len);
	free(hex_str);
}

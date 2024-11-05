/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_hex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:40:15 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/05 16:40:15 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char *get_hex_prefix(char c, t_printf *p, unsigned long long num)
{
	return (p->flags.hash && num != 0) ? ((c == 'x') ? "0x" : "0X") : "";
}

static char *convert_to_hex_str(unsigned long long num, char c)
{
	return (c == 'x') ? ft_utoa_base(num, "0123456789abcdef")
					  : ft_utoa_base(num, "0123456789ABCDEF");
}

void x_hex(t_printf *p, char c)
{
	unsigned long long num;
	const char *prefix;
	char *hex_str;
	int len;

	num = va_arg(p->ap, unsigned int);
	prefix = get_hex_prefix(c, p, num);
	hex_str = convert_to_hex_str(num, c);
	len = ft_strlen(hex_str) + ft_strlen(prefix);
	if (p->flags.minus)
	{
		x_prefix(p, prefix);
		x_precision(p, ft_strlen(hex_str));
		x_number(p, hex_str);
		x_padding(p, len, ' ');
	}
	else
	{
		x_padding(p, len, p->flags.zero ? '0' : ' ');
		x_prefix(p, prefix);
		x_precision(p, ft_strlen(hex_str));
		x_number(p, hex_str);
	}
	free(hex_str);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_hex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:47:57 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/16 20:52:38 by anpayot          ###   ########.fr       */
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
		return (ft_ulltoa_base(num, "0123456789abcdef"));
	else
		return (ft_ulltoa_base(num, "0123456789ABCDEF"));
}

void	x_hex(t_printf *p, char c)
{
	unsigned long long	num;
	const char			*prefix;
	char				*hex_str;
	int					len;

	num = va_arg(p->ap, unsigned int);

	// Handle precision 0 with value 0
	if (p->precision == 0 && num == 0)
	{
		x_padding(p, 0, ' ');
		return;
	}
	prefix = get_hex_prefix(c, p, num);
	hex_str = convert_to_hex_str(num, c);
	len = ft_strlen(hex_str) + ft_strlen(prefix);
	if (p->precision >= 0 && p->precision > len)
		len = p->precision + ft_strlen(prefix);
	if (p->flags.minus)
	{
		x_prefix(p, prefix);
		x_precision(p, ft_strlen(hex_str));
		x_number(p, hex_str);
		x_padding(p, len, ' ');
	}
	else
	{
		if (p->flags.zero)
			x_padding(p, len, '0');
		else
			x_padding(p, len, ' ');
		x_prefix(p, prefix);
		x_precision(p, ft_strlen(hex_str));
		x_number(p, hex_str);
	}
	free(hex_str);
}

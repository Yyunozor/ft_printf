/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:48:37 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/17 03:49:49 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_prefix(t_printf *p, const char *prefix)
{
	p->len += write(1, prefix, ft_strlen(prefix));
}

void	x_number(t_printf *p, const char *str)
{
	p->len += write(1, str, ft_strlen(str));
}

void	x_padding(t_printf *p, int content_len, char pad_char)
{
	int	padding_len;

	padding_len = p->width - content_len;
	if (padding_len <= 0)
		return ;
	if (p->flags.minus)
	{
		while (padding_len > 0)
		{
			p->len += write(1, " ", 1);
			padding_len--;
		}
	}
	else
	{
		if (pad_char == '0' && p->precision >= 0)
			pad_char = ' ';
		while (padding_len > 0)
		{
			p->len += write(1, &pad_char, 1);
			padding_len--;
		}
	}
}

void	x_precision(t_printf *p, int num_len)
{
	int	precision_padding;

	if (p->precision < 0)
		return ;
	precision_padding = p->precision - num_len;
	while (precision_padding > 0)
	{
		p->len += write(1, "0", 1);
		precision_padding--;
	}
}

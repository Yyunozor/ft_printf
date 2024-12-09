/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:48:37 by anpayot           #+#    #+#             */
/*   Updated: 2024/12/09 19:29:47 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"

void x_prefix(t_printf *p, const char *prefix)
{
	p->len += write(1, prefix, ft_strlen(prefix));
}

void x_number(t_printf *p, const char *str)
{
	p->len += write(1, str, ft_strlen(str));
}

// New function to handle multi-specifier spacing
static int calculate_total_width(t_printf *p, int content_len)
{
	if (p->width <= content_len)
		return 0;
	return p->width - content_len;
}

void x_padding(t_printf *p, int content_len, char pad_char)
{
	int padding_len = calculate_total_width(p, content_len);
	int i = 0;

	if (padding_len <= 0)
		return;

	while (i < padding_len)
	{
		if (p->flags.minus)
			p->len += write(1, " ", 1);
		else
			p->len += write(1, &pad_char, 1);
		i++;
	}
}

void x_precision(t_printf *p, int num_len)
{
	if (p->precision < 0 || p->precision <= num_len)
		return;

	while (num_len < p->precision)
	{
		p->len += write(1, "0", 1);
		num_len++;
	}
}

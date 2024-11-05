/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:44:25 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/05 22:12:12 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void x_prefix(t_printf *p, const char *prefix)
{
	p->len += write(1, prefix, ft_strlen(prefix));
}


void x_number(t_printf *p, const char *str)
{
	p->len += write(1, str, ft_strlen(str));
}


void x_padding(t_printf *p, int len, char pad_char)
{
	int padding_len = p->width - len;  // Calculate the exact padding required
	while (padding_len > 0)
	{
		p->len += write(1, &pad_char, 1);
		padding_len--;
	}
}

void x_precision(t_printf *p, int num_len)
{
	while (num_len < p->precision)
	{
		p->len += write(1, "0", 1);
		num_len++;
	}
}

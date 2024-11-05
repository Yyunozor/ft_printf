/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:40:44 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/05 16:41:55 by anpayot          ###   ########.fr       */
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

void	x_padding(t_printf *p, int len, char pad_char)
{
	while (len < p->width)
	{
		p->len += write(1, &pad_char, 1);
		len++;
	}
}

void	x_precision(t_printf *p, int num_len)
{
	while (num_len < p->precision)
	{
		p->len += write(1, "0", 1);
		num_len++;
	}
}
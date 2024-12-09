/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_str.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:48:37 by anpayot           #+#    #+#             */
/*   Updated: 2024/12/09 19:30:04 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"

static void handle_null_str(t_printf *p)
{
	char *null_str;
	int len;
	int padding;

	null_str = "(null)";
	len = 6;
	if (p->precision >= 0 && p->precision < len)
		len = p->precision;
	padding = p->width - len;
	if (padding < 0)
		padding = 0;

	if (p->flags.minus)
	{
		p->len += write(1, null_str, len);
		while (padding--)
			p->len += write(1, " ", 1);
	}
	else
	{
		while (padding--)
			p->len += write(1, " ", 1);
		p->len += write(1, null_str, len);
	}
}

void x_str(t_printf *p)
{
	char *str;
	int len;
	int padding;
	int total_width;

	str = va_arg(p->ap, char *);
	if (!str)
	{
		handle_null_str(p);
		return;
	}

	len = ft_strlen(str);
	if (p->precision >= 0 && p->precision < len)
		len = p->precision;
	
	total_width = p->width;
	padding = total_width - len;
	if (padding < 0)
		padding = 0;

	if (p->flags.minus)
	{
		p->len += write(1, str, len);
		x_padding(p, len, ' ');
	}
	else
	{
		x_padding(p, len, ' ');
		p->len += write(1, str, len);
	}
}

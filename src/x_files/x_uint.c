/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_uint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:48:22 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/16 20:50:54 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void x_uint(t_printf *p)
{
	unsigned int num;
	char *str;
	int len;

	num = va_arg(p->ap, unsigned int);
	if (p->precision == 0 && num == 0)
	{
		x_padding(p, 0, ' ');
		return;
	}
	str = ft_ulltoa_base(num, "0123456789");
	len = ft_strlen(str);
	if (p->precision >= 0 && p->precision > len)
		len = p->precision;
	if (p->flags.minus)
	{
		x_precision(p, ft_strlen(str));
		x_number(p, str);
		x_padding(p, len, ' ');
	}
	else
	{
		if (p->flags.zero)
			x_padding(p, len, '0');
		else
			x_padding(p, len, ' ');
		x_precision(p, ft_strlen(str));
		x_number(p, str);
	}
	free(str);
}

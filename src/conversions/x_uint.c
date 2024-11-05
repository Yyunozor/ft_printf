/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_uint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:04:20 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/05 17:04:23 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void x_uint(t_printf *p)
{
	unsigned int num;
	char *str;
	int len;

	num = va_arg(p->ap, unsigned int);
	str = ft_utoa_base(num, "0123456789");
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
		x_padding(p, len, p->flags.zero ? '0' : ' ');
		x_precision(p, ft_strlen(str));
		x_number(p, str);
	}
	free(str);
}

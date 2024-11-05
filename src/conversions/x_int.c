/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:19:33 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/05 20:51:21 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void x_int(t_printf *p)
{
	int num;
	char *str;
	char *prefix = "";
	int len;
	int num_len;

	num = va_arg(p->ap, int);
	if (num < 0)
	{
		prefix = "-";
		num = -num;
	}
	else if (num >= 0 && p->flags.plus)
		prefix = "+";
	else if (num >= 0 && p->flags.space)
		prefix = " ";
	str = ft_itoa_base(num, "0123456789");
	num_len = ft_strlen(str);
	len = num_len + ft_strlen(prefix);
	if (p->precision >= 0 && p->precision > num_len)
		len = p->precision + ft_strlen(prefix);
	if (p->flags.minus)
	{
		x_prefix(p, prefix);
		x_precision(p, num_len);
		x_number(p, str);
		x_padding(p, len, ' ');
	}
	else
	{
		if (p->flags.zero && p->precision < 0)
		{
			x_prefix(p, prefix);
			x_padding(p, len, '0');
		}
		else
		{
			x_padding(p, len, ' ');
			x_prefix(p, prefix);
		}
		x_precision(p, num_len);
		x_number(p, str);
	}
	free(str);
}

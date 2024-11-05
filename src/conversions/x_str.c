/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_str.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:03:38 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/05 17:03:44 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void x_str(t_printf *p)
{
	char *str;
	int len;

	str = va_arg(p->ap, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (p->precision >= 0 && p->precision < len)
		len = p->precision;
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

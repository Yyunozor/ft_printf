/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:30:08 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/05 16:30:34 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void x_int(t_printf *p)
{
	int num;
	char *str;
	char *prefix = "";
	int len;

	num = va_arg(p->ap, int);
	if (num >= 0 && p->flags.plus)
		prefix = "+";
	else if (num >= 0 && p->flags.space)
		prefix = " ";
	str = ft_itoa_base(num, "0123456789");
	len = ft_strlen(str) + ft_strlen(prefix);
	if (p->flags.minus)
	{
		x_prefix(p, prefix);
		x_precision(p, ft_strlen(str));
		x_number(p, str);
		x_padding(p, len, ' ');
	}
	else
	{
		x_padding(p, len, p->flags.zero ? '0' : ' ');
		x_prefix(p, prefix);
		x_precision(p, ft_strlen(str));
		x_number(p, str);
	}
	free(str);
}
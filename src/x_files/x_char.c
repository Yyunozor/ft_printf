/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_char.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:37:48 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/05 17:37:49 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void x_char(t_printf *p)
{
	char c;

	c = (char)va_arg(p->ap, int);
	if (p->flags.minus)
	{
		p->len += write(1, &c, 1);
		x_padding(p, 1, ' ');
	}
	else
	{
		if (p->flags.zero)
			x_padding(p, 1, '0');
		else
			x_padding(p, 1, ' ');
		p->len += write(1, &c, 1);
	}
}
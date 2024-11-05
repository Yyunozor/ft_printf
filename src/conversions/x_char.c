/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_char.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:54:20 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/05 16:54:24 by anpayot          ###   ########.fr       */
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
		x_padding(p, 1, p->flags.zero ? '0' : ' ');
		p->len += write(1, &c, 1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_mod.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:48:37 by anpayot           #+#    #+#             */
/*   Updated: 2024/12/09 19:30:16 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void x_mod(t_printf *p)
{
	if (p->flags.minus)
	{
		p->len += write(1, "%", 1);
		x_padding(p, 1, ' ');
	}
	else
	{
		char pad_char = p->flags.zero ? '0' : ' ';
		x_padding(p, 1, pad_char);
		p->len += write(1, "%", 1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_mod.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:55:11 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/05 16:55:19 by anpayot          ###   ########.fr       */
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
		x_padding(p, 1, p->flags.zero ? '0' : ' ');
		p->len += write(1, "%", 1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_mod.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:38:29 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/05 17:38:30 by anpayot          ###   ########.fr       */
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
		if (p->flags.zero)
			x_padding(p, 1, '0');
		else
			x_padding(p, 1, ' ');
		p->len += write(1, "%", 1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_mod.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:48:37 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/17 19:29:59 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_mod(t_printf *p)
{
	char	pad;

	pad = ' ';
	if (p->flags.zero)
		pad = '0';
	if (p->flags.minus)
	{
		p->len += write(1, "%", 1);
		x_padding(p, 1, ' ');
	}
	else
	{
		x_padding(p, 1, pad);
		p->len += write(1, "%", 1);
	}
}

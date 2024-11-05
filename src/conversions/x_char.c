/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_char.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:17:01 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/05 16:29:42 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_char(t_printf *p)
{
	char	c;

	c = va_arg(p->ap, int);
	p->len += write(1, &c, 1);
}

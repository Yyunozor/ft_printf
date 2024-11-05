/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_ptr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:56:00 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/05 16:56:20 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void x_ptr(t_printf *p)
{
	uintptr_t ptr;
	char *hex;
	const char *prefix = "0x";
	int len;

	ptr = (uintptr_t)va_arg(p->ap, void *);
	hex = ft_utoa_base(ptr, "0123456789abcdef");
	len = ft_strlen(hex) + ft_strlen(prefix);
	if (p->flags.minus)
	{
		x_prefix(p, prefix);
		x_number(p, hex);
		x_padding(p, len, ' ');
	}
	else
	{
		x_padding(p, len, p->flags.zero ? '0' : ' ');
		x_prefix(p, prefix);
		x_number(p, hex);
	}
	free(hex);
}

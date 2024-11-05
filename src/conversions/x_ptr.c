/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_ptr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:11:37 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/05 14:40:27 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void x_ptr(t_printf *p)
{
	uintptr_t	ptr;
	char		*hex;

	ptr = (uintptr_t)va_arg(p->ap, void *);
	if (ptr == 0) // Check if the pointer is NULL
	{
		p->len += write(1, "0x0", 3); // Output "0x0" for NULL pointers
		return;
	}
	hex = ft_utoa_base(ptr, "0123456789abcdef");
	p->len += write(1, "0x", 2);
	p->len += write(1, hex, ft_strlen(hex));
	free(hex);
}

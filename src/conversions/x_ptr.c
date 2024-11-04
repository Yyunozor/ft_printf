/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_ptr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:07:50 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/04 22:26:08 by anpayot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_ptr(t_printf *p)
{
	unsigned long	ptr;
	char			*hex;

	ptr = (unsigned long)va_arg(p->ap, void *);
	if (!ptr)
	{
		p->len += write(1, "(nil)", 5);
		return ;
	}
	hex = ft_itoa_base(ptr, "0123456789abcdef");
	p->len += write(1, "0x", 2);
	p->len += write(1, hex, ft_strlen(hex));
	free(hex);
}

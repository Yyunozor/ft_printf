/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_uint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:05:47 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/05 14:30:55 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void x_uint(t_printf *p)
{
	unsigned int num;
	char *str;

	num = va_arg(p->ap, unsigned int);
	str = ft_utoa_base(num, "0123456789"); // Use ft_utoa_base for unsigned integers
	p->len += write(1, str, ft_strlen(str));
	free(str);
}

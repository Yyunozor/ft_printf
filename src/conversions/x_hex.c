/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_hex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:07:24 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/04 22:07:27 by anpayot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_hex(t_printf *p, char c)
{
	unsigned int	num;
	char			*str;

	num = va_arg(p->ap, unsigned int);
	if (c == 'x')
		str = ft_itoa_base(num, "0123456789abcdef");
	else
		str = ft_itoa_base(num, "0123456789ABCDEF");
	p->len += write(1, str, ft_strlen(str));
	free(str);
}

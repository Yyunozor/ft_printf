/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:16:37 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/04 22:04:45 by anpayot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conversion(t_printf *p, char c)
{
	if (c == 'c')
		x_char(p);
	else if (c == 's')
		x_str(p);
	else if (c == 'p')
		x_ptr(p);
	else if (c == 'd' || c == 'i')
		x_int(p);
	else if (c == 'u')
		x_uint(p);
	else if (c == 'x' || c == 'X')
		x_hex(p, c);
	else if (c == '%')
		x_mod(p);
}

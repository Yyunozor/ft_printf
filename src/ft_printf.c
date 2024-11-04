/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:54:47 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/04 23:54:56 by anpayot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	t_printf p;
	ft_bzero(&p, sizeof(t_printf));
	va_start(p.ap, format);

	while (*format)
	{
		if (*format == '%' && *(++format))
		{
			parse_format(&p, &format);
			if (ft_strchr("cspdiuxX%", *format))
				ft_conversion(&p, *format);
			else
				p.len += write(1, format, 1);
		}
		else
			p.len += write(1, format, 1);
		format++;
	}
	va_end(p.ap);
	return (p.len);
}
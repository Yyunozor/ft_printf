/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:53:55 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/17 19:29:59 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_printf	p;

	ft_bzero(&p, sizeof(t_printf));
	va_start(p.ap, format);
	while (*format)
	{
		if (*format == '%' && *(++format))
		{
			ft_parse_format(&p, &format);
			if (ft_strchr("cspdiuxX%", *format))
				ft_x(&p, *format);
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

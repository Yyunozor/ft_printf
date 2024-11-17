/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_str.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:48:37 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/17 03:44:20 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_null_str(t_printf *p)
{
	char	*null_str;
	int		len;

	null_str = "(null)";
	len = 6;
	if (p->precision >= 0 && p->precision < len)
		len = p->precision;
	if (p->flags.minus)
	{
		p->len += write(1, null_str, len);
		x_padding(p, len, ' ');
	}
	else
	{
		x_padding(p, len, ' ');
		p->len += write(1, null_str, len);
	}
}

void	x_str(t_printf *p)
{
	char	*str;
	int		len;

	str = va_arg(p->ap, char *);
	if (!str)
	{
		handle_null_str(p);
		return ;
	}
	len = ft_strlen(str);
	if (p->precision >= 0 && p->precision < len)
		len = p->precision;
	if (p->flags.minus)
	{
		p->len += write(1, str, len);
		x_padding(p, len, ' ');
	}
	else
	{
		x_padding(p, len, ' ');
		p->len += write(1, str, len);
	}
}

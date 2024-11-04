/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_str.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:15:27 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/04 21:15:27 by anpayot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_str(t_printf *p)
{
	char	*str;

	str = va_arg(p->ap, char *);
	if (!str)
		str = "(null)";
	p->len += write(1, str, ft_strlen(str));
}

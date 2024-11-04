/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_uint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:33:32 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/04 22:33:45 by anpayot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_uint(t_printf *p)
{
	unsigned int	num;
	char			*str;

	num = va_arg(p->ap, unsigned int);
	str = ft_itoa_base(num, "0123456789");
	p->len += write(1, str, ft_strlen(str));
	free(str);
}

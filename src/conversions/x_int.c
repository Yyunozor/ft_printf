/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:33:22 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/04 22:33:22 by anpayot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_int(t_printf *p)
{
	int		num;
	char	*str;
	char	*prefix = "";

	num = va_arg(p->ap, int);
	if (num >= 0 && p->flags.plus)
		prefix = "+";
	str = ft_itoa_base(num, "0123456789");
	p->len += write(1, prefix, ft_strlen(prefix));
	p->len += write(1, str, ft_strlen(str));
	free(str);
}

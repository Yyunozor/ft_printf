/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:45:03 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/16 20:49:20 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_int(t_printf *p)
{
	long long	num;
	char		*str;
	const char	*prefix = "";
	int 		len; 
	int			num_len;

	num = va_arg(p->ap, int);

	// Handle precision 0 with value 0
	if (p->precision == 0 && num == 0)
	{
		x_padding(p, 0, ' ');
		return;
	}

	// Determine the prefix based on sign and flags
	if (num < 0)
	{
		prefix = "-";
		num = -num;
	}
	else if (p->flags.plus)
		prefix = "+";
	else if (p->flags.space)
		prefix = " ";

	// Convert number to string
str = ft_ulltoa_base(num, "0123456789");
	num_len = ft_strlen(str);
	len = num_len + ft_strlen(prefix);

	if (p->precision > num_len)
		len = p->precision + ft_strlen(prefix);

	if (p->flags.minus)
	{
		x_prefix(p, prefix);
		x_precision(p, num_len);
		x_number(p, str);
		x_padding(p, len, ' ');
	}
	else
	{
		// Handle zero padding correctly
		if (p->flags.zero && p->precision < 0)
		{
			x_prefix(p, prefix);
			x_padding(p, len, '0');
		}
		else
		{
			x_padding(p, len, ' ');
			x_prefix(p, prefix);
			x_precision(p, num_len);
		}
		x_number(p, str);
	}

	free(str);
}

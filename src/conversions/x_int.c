/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:45:03 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/05 21:46:34 by anpayot          ###   ########.fr       */
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

	// Adjust total length for precision if it's greater than num_len
	if (p->precision > num_len)
		len = p->precision + ft_strlen(prefix);

	// Left alignment
	if (p->flags.minus)
	{
		x_prefix(p, prefix);
		x_precision(p, num_len);
		x_number(p, str);
		x_padding(p, len, ' ');
	}
	else
	{
		if (p->flags.zero && p->precision < 0)
		{
			// Zero-padding without precision
			x_prefix(p, prefix);
			x_padding(p, len, '0');
		}
		else
		{
			// Space-padding with precision or without zero flag
			x_padding(p, len, ' ');
			x_prefix(p, prefix);
		}
		x_precision(p, num_len);
		x_number(p, str);
	}

	free(str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_ptr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:48:37 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/17 03:42:04 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_ptr_format(t_format_data *data, t_printf *p)
{
	uintptr_t	ptr;

	ptr = (uintptr_t)va_arg(p->ap, void *);
	data->prefix = "0x";
	data->str = ft_ulltoa_base(ptr, "0123456789abcdef");
	data->num_len = ft_strlen(data->str);
	data->len = data->num_len + ft_strlen(data->prefix);
	if (p->precision > data->num_len)
		data->len = p->precision + ft_strlen(data->prefix);
}

static void	print_ptr_null(t_printf *p)
{
	const char	*null_ptr = "0x0";
	int			len;

	len = ft_strlen(null_ptr);
	if (p->flags.minus)
	{
		x_number(p, null_ptr);
		x_padding(p, len, ' ');
	}
	else
	{
		x_padding(p, len, ' ');
		x_number(p, null_ptr);
	}
}

void	x_ptr(t_printf *p)
{
	t_format_data	data;

	init_ptr_format(&data, p);
	if (!data.str)
	{
		print_ptr_null(p);
		return ;
	}
	if (p->flags.minus)
	{
		x_prefix(p, data.prefix);
		x_number(p, data.str);
		x_padding(p, data.len, ' ');
	}
	else
	{
		x_padding(p, data.len, ' ');
		x_prefix(p, data.prefix);
		x_number(p, data.str);
	}
	free(data.str);
}

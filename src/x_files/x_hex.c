/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_hex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:47:57 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/17 03:44:12 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_hex_prefix(t_format_data *data, t_printf *p)
{
	if (p->flags.hash && data->num != 0)
		data->prefix = data->prefix;
	else
		data->prefix = "";
}

static void	init_hex_format(t_format_data *data, t_printf *p, char c)
{
	const char	*base;

	data->num = va_arg(p->ap, unsigned int);
	if (c == 'x')
	{
		base = "0123456789abcdef";
		data->prefix = "0x";
	}
	else
	{
		base = "0123456789ABCDEF";
		data->prefix = "0X";
	}
	data->str = ft_ulltoa_base(data->num, base);
	set_hex_prefix(data, p);
	data->num_len = ft_strlen(data->str);
	data->len = data->num_len;
	if (p->precision > data->num_len)
		data->len = p->precision;
	data->len += ft_strlen(data->prefix);
}

static void	print_hex_left(t_printf *p, t_format_data *data)
{
	x_prefix(p, data->prefix);
	x_precision(p, data->num_len);
	x_number(p, data->str);
	x_padding(p, data->len, ' ');
}

static void	print_hex_right(t_printf *p, t_format_data *data)
{
	char	pad;

	pad = ' ';
	if (p->flags.zero && p->precision < 0)
		pad = '0';
	if (pad == '0')
	{
		x_prefix(p, data->prefix);
		x_padding(p, data->len, '0');
	}
	else
	{
		x_padding(p, data->len, ' ');
		x_prefix(p, data->prefix);
		x_precision(p, data->num_len);
	}
	x_number(p, data->str);
}

void	x_hex(t_printf *p, char c)
{
	t_format_data	data;

	init_hex_format(&data, p, c);
	if (p->precision == 0 && data.num == 0)
	{
		x_padding(p, p->width, ' ');
		free(data.str);
		return ;
	}
	if (p->flags.minus)
		print_hex_left(p, &data);
	else
		print_hex_right(p, &data);
	free(data.str);
}

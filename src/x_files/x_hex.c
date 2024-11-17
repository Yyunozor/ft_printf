/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_hex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:47:57 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/17 19:40:39 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_zero_case(t_printf *p)
{
	int	padding_len;

	padding_len = p->width - 1;
	if (p->precision == 0)
	{
		while (p->width > 0)
		{
			p->len += write(1, " ", 1);
			p->width--;
		}
		return ;
	}
	while (padding_len > 0)
	{
		p->len += write(1, " ", 1);
		padding_len--;
	}
	p->len += write(1, "0", 1);
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
	if (p->flags.hash && data->num != 0)
		data->prefix = data->prefix;
	else
		data->prefix = "";
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
	while (p->width > data->len)
	{
		p->len += write(1, " ", 1);
		p->width--;
	}
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
		while (p->width > data->len)
		{
			p->len += write(1, "0", 1);
			p->width--;
		}
		x_precision(p, data->num_len);
	}
	else
	{
		while (p->width > data->len)
		{
			p->len += write(1, " ", 1);
			p->width--;
		}
		x_prefix(p, data->prefix);
		x_precision(p, data->num_len);
	}
	x_number(p, data->str);
}

void	x_hex(t_printf *p, char c)
{
	t_format_data	data;

	init_hex_format(&data, p, c);
	if (data.num == 0 && p->precision == 0)
	{
		handle_zero_case(p);
		free(data.str);
		return ;
	}
	if (data.num == 0)
		data.prefix = "";
	if (p->flags.minus)
		print_hex_left(p, &data);
	else
		print_hex_right(p, &data);
	free(data.str);
}

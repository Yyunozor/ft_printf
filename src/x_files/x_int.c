/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_int.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:45:03 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/17 19:29:59 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_zero_case(t_printf *p, const char *prefix)
{
	int	len;

	if (p->flags.plus)
		prefix = "+";
	else if (p->flags.space)
		prefix = " ";
	len = ft_strlen(prefix);
	if (p->flags.minus)
	{
		x_prefix(p, prefix);
		x_padding(p, len, ' ');
	}
	else
	{
		x_padding(p, len, ' ');
		x_prefix(p, prefix);
	}
}

static void	handle_formatting(t_printf *p, t_format_data *data)
{
	if (data->num < 0)
	{
		data->prefix = "-";
		data->num = -(data->num);
	}
	else if (p->flags.plus)
		data->prefix = "+";
	else if (p->flags.space)
		data->prefix = " ";
	data->str = ft_ulltoa_base(data->num, "0123456789");
	data->num_len = ft_strlen(data->str);
	data->len = data->num_len + ft_strlen(data->prefix);
	if (p->precision > data->num_len)
		data->len = p->precision + ft_strlen(data->prefix);
}

static void	print_left_aligned(t_printf *p, t_format_data *data)
{
	x_prefix(p, data->prefix);
	x_precision(p, data->num_len);
	x_number(p, data->str);
	x_padding(p, data->len, ' ');
}

static void	print_right_aligned(t_printf *p, t_format_data *data)
{
	char	pad_char;

	pad_char = ' ';
	if (p->flags.zero && p->precision < 0)
		pad_char = '0';
	if (pad_char == '0')
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

void	x_int(t_printf *p)
{
	t_format_data	data;

	data.num = va_arg(p->ap, int);
	data.prefix = "";
	if (p->precision == 0 && data.num == 0)
	{
		handle_zero_case(p, data.prefix);
		return ;
	}
	handle_formatting(p, &data);
	if (p->flags.minus)
		print_left_aligned(p, &data);
	else
		print_right_aligned(p, &data);
	free(data.str);
}

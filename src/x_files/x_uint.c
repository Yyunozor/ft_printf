/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_uint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:48:37 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/17 19:42:03 by anpayot          ###   ########.fr       */
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

static void	print_uint_left(t_printf *p, char *str, int total_len, int num_len)
{
	x_precision(p, num_len);
	x_number(p, str);
	while (p->width > total_len)
	{
		p->len += write(1, " ", 1);
		p->width--;
	}
}

static void	print_uint_right(t_printf *p, char *str, int total_len, int num_len)
{
	char	pad;

	pad = ' ';
	if (p->flags.zero && p->precision < 0)
		pad = '0';
	if (pad == '0')
	{
		while (p->width > total_len)
		{
			p->len += write(1, "0", 1);
			p->width--;
		}
		x_precision(p, num_len);
	}
	else
	{
		while (p->width > total_len)
		{
			p->len += write(1, " ", 1);
			p->width--;
		}
		x_precision(p, num_len);
	}
	x_number(p, str);
}

void	x_uint(t_printf *p)
{
	unsigned int	num;
	char			*str;
	int				num_len;
	int				total_len;

	num = va_arg(p->ap, unsigned int);
	if (num == 0 && p->precision == 0)
	{
		handle_zero_case(p);
		return ;
	}
	str = ft_ulltoa_base(num, "0123456789");
	num_len = ft_strlen(str);
	total_len = num_len;
	if (p->precision > num_len)
		total_len = p->precision;
	if (p->flags.minus)
		print_uint_left(p, str, total_len, num_len);
	else
		print_uint_right(p, str, total_len, num_len);
	free(str);
}

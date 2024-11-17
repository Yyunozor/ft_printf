/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:48:37 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/17 19:41:43 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_prefix(t_printf *p, const char *prefix)
{
	p->len += write(1, prefix, ft_strlen(prefix));
}

void	x_number(t_printf *p, const char *str)
{
	p->len += write(1, str, ft_strlen(str));
}

static void	handle_left_padding(t_printf *p, int padding_len)
{
	int	i;

	i = 0;
	while (i < padding_len)
	{
		p->len += write(1, " ", 1);
		i++;
	}
}

static void	handle_right_padding(t_printf *p, int padding_len, char pad_char)
{
	int	i;

	i = 0;
	while (i < padding_len)
	{
		p->len += write(1, &pad_char, 1);
		i++;
	}
}

void	x_padding(t_printf *p, int content_len, char pad_char)
{
	int	padding_len;

	padding_len = p->width - content_len;
	if (padding_len <= 0)
		return ;
	if (p->flags.minus)
		handle_left_padding(p, padding_len);
	else
		handle_right_padding(p, padding_len, pad_char);
}

void	x_precision(t_printf *p, int num_len)
{
	int	precision_padding;
	int	i;

	if (p->precision < 0)
		return ;
	precision_padding = p->precision - num_len;
	if (precision_padding <= 0)
		return ;
	i = 0;
	while (i < precision_padding)
	{
		p->len += write(1, "0", 1);
		i++;
	}
}

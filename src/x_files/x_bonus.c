/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:48:37 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/17 19:29:58 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_flags(t_printf *p, const char **format)
{
	while (ft_strchr("-0+ #", **format))
	{
		if (**format == '-')
			p->flags.minus = 1;
		else if (**format == '0')
			p->flags.zero = 1;
		else if (**format == '+')
			p->flags.plus = 1;
		else if (**format == ' ')
			p->flags.space = 1;
		else if (**format == '#')
			p->flags.hash = 1;
		(*format)++;
	}
	if (p->flags.minus)
		p->flags.zero = 0;
	if (p->flags.plus)
		p->flags.space = 0;
}

static void	parse_width(t_printf *p, const char **format)
{
	p->width = 0;
	while (ft_isdigit(**format))
	{
		p->width = p->width * 10 + (**format - '0');
		(*format)++;
	}
}

static void	parse_precision(t_printf *p, const char **format)
{
	if (**format != '.')
	{
		p->precision = -1;
		return ;
	}
	(*format)++;
	p->precision = 0;
	while (ft_isdigit(**format))
	{
		p->precision = p->precision * 10 + (**format - '0');
		(*format)++;
	}
}

void	ft_parse_format(t_printf *p, const char **format)
{
	ft_bzero(&p->flags, sizeof(t_flags));
	parse_flags(p, format);
	parse_width(p, format);
	parse_precision(p, format);
}

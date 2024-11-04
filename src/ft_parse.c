#include "ft_printf.h"

static void parse_flags(t_printf *p, const char **format)
{
	while (**format == '-' || **format == '0' || **format == '#' || **format == ' ' || **format == '+')
	{
		if (**format == '-') p->flags.minus = 1;
		else if (**format == '0') p->flags.zero = 1;
		else if (**format == '+') p->flags.plus = 1;
		else if (**format == ' ') p->flags.space = 1;
		else if (**format == '#') p->flags.hash = 1;
		(*format)++;
	}
}

static void parse_width(t_printf *p, const char **format)
{
	p->width = 0;
	while (**format >= '0' && **format <= '9')
	{
		p->width = p->width * 10 + (**format - '0');
		(*format)++;
	}
}

static void parse_precision(t_printf *p, const char **format)
{
	p->precision = -1;
	if (**format == '.')
	{
		(*format)++;
		p->precision = 0;
		while (**format >= '0' && **format <= '9')
		{
			p->precision = p->precision * 10 + (**format - '0');
			(*format)++;
		}
	}
}

void parse_format(t_printf *p, const char **format)
{
	parse_flags(p, format);
	parse_width(p, format);
	parse_precision(p, format);
}

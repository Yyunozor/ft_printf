#include "ft_printf.h"

static void write_prefix(t_printf *p, const char *prefix)
{
	p->len += write(1, prefix, ft_strlen(prefix));
}

static void write_number(t_printf *p, const char *str)
{
	p->len += write(1, str, ft_strlen(str));
}

static void write_padding(t_printf *p, int len)
{
	while (len < p->width)
	{
		p->len += write(1, p->flags.zero ? "0" : " ", 1);
		len++;
	}
}

void x_int(t_printf *p)
{
	int num;
	char *str;
	char *prefix = "";
	int len;

	num = va_arg(p->ap, int);
	if (num >= 0 && p->flags.plus)
		prefix = "+";
	else if (num >= 0 && p->flags.space)
		prefix = " ";
	str = ft_itoa_base(num, "0123456789");
	len = ft_strlen(str) + ft_strlen(prefix);
	if (p->flags.minus)
	{
		write_prefix(p, prefix);
		write_number(p, str);
		write_padding(p, len);
	}
	else
	{
		write_padding(p, len);
		write_prefix(p, prefix);
		write_number(p, str);
	}
	free(str);
}

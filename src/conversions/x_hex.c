/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_hex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 30/10/2024 21:14:40 by anpayot           #+#    #+#             */
/*   Updated: 05/11/2024 14:56:47 by anpayot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Helper function to get the hexadecimal prefix based on the specifier and number.
static const char *get_hex_prefix(char c, t_printf *p, unsigned long long num) {
	return (p->flags.hash && num != 0) ? ((c == 'x') ? "0x" : "0X") : "";
}

// Helper function to convert the number to a hexadecimal string.
static char *convert_to_hex_str(unsigned long long num, char c) {
	return (c == 'x') ? ft_utoa_base(num, "0123456789abcdef")
					  : ft_utoa_base(num, "0123456789ABCDEF");
}

// Helper to calculate the final length of the output, considering precision and prefix.
static int calculate_output_len(t_printf *p, const char *prefix, const char *hex_str) {
	int len = ft_strlen(prefix) + ft_strlen(hex_str);
	if (p->precision > (int)ft_strlen(hex_str)) {
		len += (p->precision - (int)ft_strlen(hex_str));
	}
	return len;
}

// Write left-aligned output
static void write_left_aligned(t_printf *p, const char *prefix, const char *hex_str, int output_len) {
	p->len += write(1, prefix, ft_strlen(prefix));
	for (int i = 0; i < p->precision - (int)ft_strlen(hex_str); i++)
		p->len += write(1, "0", 1);
	p->len += write(1, hex_str, ft_strlen(hex_str));
	while (output_len < p->width)
		p->len += write(1, " ", 1), output_len++;
}

// Write padded (right-aligned or zero-padded) output
static void write_padded(t_printf *p, const char *prefix, const char *hex_str, int output_len) {
	char pad_char = (p->flags.zero && p->precision == -1) ? '0' : ' ';
	int prefix_len = ft_strlen(prefix);

	// Write padding if width is larger than the output length.
	while (output_len < p->width && pad_char == ' ')
		p->len += write(1, " ", 1), output_len++;
	
	p->len += write(1, prefix, prefix_len);

	while (output_len < p->width && pad_char == '0')
		p->len += write(1, "0", 1), output_len++;
	
	// Write leading zeros for precision.
	for (int i = 0; i < p->precision - (int)ft_strlen(hex_str); i++)
		p->len += write(1, "0", 1);
	
	// Write the actual hex string.
	p->len += write(1, hex_str, ft_strlen(hex_str));
}

// Main function for hexadecimal conversion
void x_hex(t_printf *p, char c) {
	unsigned long long num = va_arg(p->ap, unsigned long long);
	const char *prefix = get_hex_prefix(c, p, num);
	char *hex_str = convert_to_hex_str(num, c);
	int output_len = calculate_output_len(p, prefix, hex_str);

	if (p->flags.minus)
		write_left_aligned(p, prefix, hex_str, output_len);
	else
		write_padded(p, prefix, hex_str, output_len);

	free(hex_str);
}

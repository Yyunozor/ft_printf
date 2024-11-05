#include "ft_printf.h"
#include <limits.h>

// Get prefix based on the hash flag and specifier (lower or uppercase)
static const char *get_hex_prefix(char specifier, t_printf *p, unsigned long long num) {
	const char *prefix = "";
	if (p->flags.hash && num != 0) {
		if (specifier == 'x') {
			prefix = "0x";
		} else {
			prefix = "0X";
		}
	}
	return prefix;
}

// Convert an unsigned integer to a hex string (base 16), using lowercase or uppercase
static char *convert_to_hex_str(unsigned long long num, char specifier) {
	char *hex_str;
	if (specifier == 'x') {
		hex_str = ft_utoa_base(num, "0123456789abcdef");
	} else {
		hex_str = ft_utoa_base(num, "0123456789ABCDEF");
	}
	return hex_str;
}

// Calculate the length needed to output the hexadecimal string with prefix and precision
static int calculate_output_len(t_printf *p, const char *prefix, const char *hex_str) {
	int len = ft_strlen(prefix) + ft_strlen(hex_str);
	if (p->precision > (int)ft_strlen(hex_str)) {
		len += p->precision - ft_strlen(hex_str);
	}
	return len;
}

// Write left-aligned hexadecimal output with precision and width management
static void write_left_aligned(t_printf *p, const char *prefix, const char *hex_str, int output_len) {
	p->len += write(1, prefix, ft_strlen(prefix));
	int i = 0;
	while (i < p->precision - (int)ft_strlen(hex_str)) {
		p->len += write(1, "0", 1);
		i++;
	}
	p->len += write(1, hex_str, ft_strlen(hex_str));
	while (output_len < p->width) {
		p->len += write(1, " ", 1);
		output_len++;
	}
}

// Write padded (right-aligned or zero-padded) output for hexadecimal
static void write_padded(t_printf *p, const char *prefix, const char *hex_str, int output_len) {
	char pad_char;
	if (p->flags.zero && p->precision == -1) {
		pad_char = '0';
	} else {
		pad_char = ' ';
	}
	int prefix_len = ft_strlen(prefix);

	// Space padding for non-zero padding
	while (output_len < p->width && pad_char == ' ') {
		p->len += write(1, " ", 1);
		output_len++;
	}

	// Write prefix if required
	p->len += write(1, prefix, prefix_len);

	// Zero padding if applicable
	while (output_len < p->width && pad_char == '0') {
		p->len += write(1, "0", 1);
		output_len++;
	}

	// Precision padding with zeros
	int i = 0;
	while (i < p->precision - (int)ft_strlen(hex_str)) {
		p->len += write(1, "0", 1);
		i++;
	}

	// Finally, write the hexadecimal string
	p->len += write(1, hex_str, ft_strlen(hex_str));
}

void x_hex(t_printf *p, char c) {
	unsigned long long num;

	// Retrieve the correct type directly as unsigned long long for large values
	num = va_arg(p->ap, unsigned long long);

	const char *prefix = get_hex_prefix(c, p, num);
	char *hex_str = convert_to_hex_str(num, c);      // Convert number to hexadecimal string
	int output_len = calculate_output_len(p, prefix, hex_str);

	// Apply left or right alignment based on flags
	if (p->flags.minus)
		write_left_aligned(p, prefix, hex_str, output_len);
	else
		write_padded(p, prefix, hex_str, output_len);

	free(hex_str);  // Free dynamically allocated hex string
}

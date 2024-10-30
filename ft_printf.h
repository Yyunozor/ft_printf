#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

// Function prototypes
int ft_printf(const char *format, ...);
int x_char(va_list args);
int x_string(va_list args);
int x_pointer(va_list args);
int x_integer(va_list args);
int x_unsigned(va_list args);
int x_hex(va_list args, char specifier);
int x_percent(void);

// Utility function prototypes
char *ft_itoa_base(int value, int base);
void ft_putnbr(int n);
void ft_putchar(char c);
void ft_putstr(char *s);

#endif // FT_PRINTF_H
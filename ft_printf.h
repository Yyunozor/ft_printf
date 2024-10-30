/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:37:21 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/30 21:40:04 by anpayot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

// Function prototypes
int		ft_printf(const char *format, ...);
int		x_char(va_list args);
int		x_str(va_list args);
int		x_ptr(va_list args);
int		x_int(va_list args);
int		x_uint(va_list args);
int		x_hex(va_list args, char specifier);
int		x_mod(void);

// Bonus feature prototypes
int		x_bonus(va_list args, char specifier, int width, int precision);

// Utility function prototypes
char	*ft_itoa_base(int value, int base);
void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_putstr(char *s);

#endif // FT_PRINTF_H
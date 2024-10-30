/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:02:14 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/30 23:26:56 by anpayot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
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

#endif // FT_PRINTF_H
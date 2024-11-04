/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:04:15 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/04 22:04:15 by anpayot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_printf
{
	va_list	ap;
	int		len;
}	t_printf;

// Function prototypes
int		ft_printf(const char *format, ...);
void	x_char(t_printf *p);
void	x_str(t_printf *p);
void	x_ptr(t_printf *p);
void	x_int(t_printf *p);
void	x_uint(t_printf *p);
void	x_hex(t_printf *p, char specifier);
void	x_mod(t_printf *p);
void	ft_conversion(t_printf *p, char specifier);

#endif // FT_PRINTF_H
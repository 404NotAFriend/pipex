/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 00:00:00 by bramalho          #+#    #+#             */
/*   Updated: 2025/12/16 11:32:44 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		print_char(int c);
int		print_str(char *str);
int		print_ptr(unsigned long ptr);
int		print_nbr(int n);
int		print_unsigned(unsigned int n);
int		print_hex(unsigned int n, int uppercase);

#endif

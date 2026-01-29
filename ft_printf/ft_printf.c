/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 00:00:00 by bramalho          #+#    #+#             */
/*   Updated: 2025/11/08 15:28:18 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	handle_format(char type, va_list args)
{
	int	counter;

	counter = 0;
	if (type == 'c')
		counter = print_char(va_arg(args, int));
	else if (type == 's')
		counter = print_str(va_arg(args, char *));
	else if (type == 'p')
		counter = print_ptr(va_arg(args, unsigned long));
	else if (type == 'd' || type == 'i')
		counter = print_nbr(va_arg(args, int));
	else if (type == 'u')
		counter = print_unsigned(va_arg(args, unsigned int));
	else if (type == 'x')
		counter = print_hex(va_arg(args, unsigned int), 0);
	else if (type == 'X')
		counter = print_hex(va_arg(args, unsigned int), 1);
	else if (type == '%')
		counter = print_char('%');
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;
	int		i;

	if (!format)
		return (-1);
	va_start(args, format);
	counter = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			counter += handle_format(format[i], args);
		}
		else
			counter += print_char(format[i]);
		i++;
	}
	va_end(args);
	return (counter);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bramalho@student.42porto.com <bramalho>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 00:00:00 by bramalho          #+#    #+#             */
/*   Updated: 2025/11/08 15:29:40 by bramalho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int	len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (len);
}

int	print_ptr(unsigned long ptr)
{
	int	counter;

	counter = 0;
	if (ptr == 0)
	{
		counter += print_str("(nil)");
		return (counter);
	}
	counter += print_str("0x");
	ft_putnbr_base_fd(ptr, "0123456789abcdef", 1);
	counter += ft_unumlen_base(ptr, 16);
	return (counter);
}

int	print_nbr(int n)
{
	long	num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num = -num;
		ft_putnbr_base_fd(num, "0123456789", 1);
		return (ft_numlen_base(num, 10) + 1);
	}
	ft_putnbr_base_fd(num, "0123456789", 1);
	return (ft_numlen_base(num, 10));
}

int	print_unsigned(unsigned int n)
{
	ft_putnbr_base_fd(n, "0123456789", 1);
	return (ft_unumlen_base(n, 10));
}

int	print_hex(unsigned int n, int uppercase)
{
	char	*base;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	ft_putnbr_base_fd(n, base, 1);
	return (ft_unumlen_base(n, 16));
}

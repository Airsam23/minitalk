/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshamdin <sshamdin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 23:55:12 by sshamdin          #+#    #+#             */
/*   Updated: 2023/07/19 23:55:32 by sshamdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, char format)
{
	int	print_len;

	print_len = 0;
	if (format == '%')
		print_len += ft_putchar(format);
	else if (format == 'c')
		print_len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		print_len += ft_print_s(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		print_len += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		print_len += ft_uputnbr(va_arg(args, int));
	else if (format == 'p')
		print_len += ft_putaddr(va_arg(args, unsigned long long));
	else if (format == 'x' || format == 'X')
		print_len += ft_puthexa(va_arg(args, unsigned long long), format);
	else
		print_len += ft_print_s(va_arg(args, char *));
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		print_len;

	va_start(args, str);
	if (!str)
		return (0);
	print_len = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			++str;
			print_len += ft_format(args, *str);
		}
		else
		{
			ft_putchar(*str);
			print_len++;
		}
		++str;
	}
	va_end(args);
	return (print_len);
}

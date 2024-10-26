/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshamdin <sshamdin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 00:02:53 by sshamdin          #+#    #+#             */
/*   Updated: 2023/07/20 00:03:21 by sshamdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(uintptr_t num, int len)
{
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static int	ft_put_ptr(uintptr_t num, const char format)
{
	int	len;

	len = 0;
	if (num >= 16)
	{
		ft_put_ptr(num / 16, format);
		ft_put_ptr(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
		{
			if (format == 'x')
				ft_putchar((num - 10 + 'a'));
			else if (format == 'X')
				ft_putchar((num - 10 + 'A'));
		}
	}
	len++;
	return (len);
}

int	ft_puthexa(unsigned int ptr, const char format)
{
	int	len;

	len = 0;
	if (ptr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		ft_put_ptr(ptr, format);
		len += ft_ptr_len(ptr, len);
	}
	return (len);
}

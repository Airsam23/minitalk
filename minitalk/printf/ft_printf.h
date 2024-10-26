/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshamdin <sshamdin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 23:56:45 by sshamdin          #+#    #+#             */
/*   Updated: 2023/07/19 23:57:01 by sshamdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

int		ft_print_s(char *str);
int		ft_printf(const char *str, ...);
int		ft_putaddr(unsigned long long ptr);
int		ft_putchar(int c);
int		ft_puthexa(unsigned int ptr, const char format);
int		ft_putnbr(int n);
void	ft_putstr(const char *s);
int		ft_strlen(const char *s);
int		ft_uputnbr(unsigned int n);

#endif

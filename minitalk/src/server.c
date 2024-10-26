/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshamdin <sshamdin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 23:30:10 by sshamdin          #+#    #+#             */
/*   Updated: 2023/07/19 23:30:43 by sshamdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"


/*This function converts a stream of incoming binary signals (SIGUSR1) into a sequence of characters, assuming each group of 8 consecutive signals represents one ASCII character, and then outputs the characters.*/

void	btoa(int sig)
{
	static int	bit_count;
	static int	byte;

	if (sig == SIGUSR1)
		byte |= (0x01 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		ft_printf("%c", byte);
		bit_count = 0;
		byte = 0;
	}
}


/*This program listens for incoming signals (SIGUSR1 and SIGUSR2) and converts them into ASCII characters, printing the characters whenever a group of 8 signals is received. If any command-line arguments are provided, it displays an error message and exits; otherwise, it continuously listens for signals.*/

int	main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	ft_printf("%d\n", getpid());
	while (argc == 1)
	{
		signal(SIGUSR1, btoa);
		signal(SIGUSR2, btoa);
		pause();
	}
	return (0);
}

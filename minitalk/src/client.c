/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshamdin <sshamdin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 23:29:04 by sshamdin          #+#    #+#             */
/*   Updated: 2023/07/19 23:29:56 by sshamdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


/*This function sends a character 'c' as a binary signal to the process with the specified PID ('pid'). It sends each bit of the character sequentially as either SIGUSR1 (if the bit is 1) or SIGUSR2 (if the bit is 0), with a small delay between each signal to ensure proper reception.*/

void	atob(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

/*This function converts a string 'str' to an integer, considering the sign and skipping any leading whitespace characters. It then iterates through the digits in the string, building the integer result, and returns the final value.*/
int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

/*This program takes two command-line arguments and sends each character of the second argument as binary signals to the process specified by the first argument (PID). It appends a newline character at the end of the transmission and then terminates.*/

int	main(int argc, char *argv[])
{
	int	i;
	int	pid;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			atob(pid, argv[2][i]);
			i++;
		}
		atob(pid, '\n');
	}
	return (0);
}

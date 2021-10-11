/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 13:47:01 by mchatzip          #+#    #+#             */
/*   Updated: 2021/07/30 13:30:09 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	confirmserver(int pid, int signal)
{
	if (kill(pid, signal))
	{
		write(2, "Recipient not found\n", 20);
		return (0);
	}
	else
		return (1);
}

void	send_bit_by_bit(int pid, char *msg, size_t len)
{
	int		shift;
	size_t	i;

	i = -1;
	while (++i <= len)
	{
		shift = -1;
		while (++shift < 7)
		{
			if ((msg[i] >> shift) & 1)
			{
				if (!confirmserver(pid, SIGUSR2))
					return ;
			}
			else
			{
				if (!confirmserver(pid, SIGUSR1))
					return ;
			}
			usleep(100);
		}
	}
}

int	PIDcheck(char *argv1)
{
	int	i;

	i = -1;
	while (argv1[++i])
	{
		if (!ft_isdigit(argv1[i]))
		{
			write(2, "Error, invalid PID\n", 19);
			return (0);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 1)
	{
		write(2, "No PID and message passed\n", 26);
		return (0);
	}
	else if (argc == 2)
	{
		write(2, "No message passed\n", 18);
		return (0);
	}
	else if (argc > 3)
	{
		write(2, "too many arguments\n", 19);
		return (0);
	}
	if (!PIDcheck(argv[1]))
		return (0);
	pid = ft_atoi(argv[1]);
	send_bit_by_bit(pid, argv[2], ft_strlen(argv[2]));
	return (1);
}

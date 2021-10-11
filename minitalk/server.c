/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 13:43:07 by mchatzip          #+#    #+#             */
/*   Updated: 2021/07/30 15:04:23 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_msg	g_msg;

void	print_pid(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	write(1, "pid: ", 5);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	free(pid);
}

void	get_bit_by_bit(int bit)
{
	if (bit == SIGUSR1)
		g_msg.c &= (1 << g_msg.size ^ 0XFF);
	else
		g_msg.c |= 1 << g_msg.size;
	g_msg.size++;
	if (g_msg.size == 7)
	{
		ft_putchar_fd(g_msg.c, 1);
		if (!g_msg.c)
			ft_putchar_fd('\n', 1);
		g_msg.c = 0;
		g_msg.size = 0;
	}
}

int	main(void)
{
	g_msg.c = 0;
	g_msg.size = 0;
	print_pid();
	while (1)
	{
		signal(SIGUSR2, get_bit_by_bit);
		signal(SIGUSR1, get_bit_by_bit);
		pause();
	}
}

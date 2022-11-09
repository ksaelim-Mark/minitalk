/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:20:55 by ksaelim           #+#    #+#             */
/*   Updated: 2022/10/20 00:28:25 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sendserver(int pid, unsigned char byte)
{
	static int	shift;

	shift = 7;
	while (shift >= 0)
	{
		if (!(byte & (1 << shift--)))
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(1, "bad pid\n", 9);
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(1, "bad pid\n", 9);
				exit(1);
			}
		}
		usleep(100);
	}
}

void	handler(char *s_pid, char *str)
{
	static int	i_pid;

	i_pid = ft_atoi(s_pid);
	if (i_pid > 0)
	{
		while (*str)
		{
			sendserver(i_pid, *str++);
			usleep(100);
		}
	}
	else
		write(1, "Invalid Pid!\n", 13);
}

static	void	message(int sig)
{
	(void)sig;
	write(1, "0", 1);
}

int	main(int ac, char **av)
{
	signal(SIGUSR1, message);
	(void)av;
	if (ac != 3)
		exit(1);
	handler(av[1], av[2]);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:20:33 by ksaelim           #+#    #+#             */
/*   Updated: 2022/10/20 00:20:33 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signbr, siginfo_t *info, void *ucontext)
{
	static char	c = 0;
	static int	bit = 7;

	(void)ucontext;
	if (signbr == SIGUSR2)
		c += (1 << bit);
	bit--;
	if (bit == -1)
	{
		write(1, &c, 1);
		c = 0;
		bit = 7;
		if (signbr == SIGUSR1)
			kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sigact;

	write(1, "pid: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sigemptyset(&sigact.sa_mask);
	sigact.sa_sigaction = &handler;
	sigact.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
	{
		usleep(50);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:58:46 by ksaelim           #+#    #+#             */
/*   Updated: 2022/10/20 00:27:50 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	n;

	i = 0;
	sign = 1;
	n = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		n = (n * 10) + (str[i++] - '0');
	return (n * sign);
}

void	ft_putnbr(int n)
{
	char		s;
	int			i;

	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n == 0)
		write (1, "0", 1);
	else
	{
		if (n < 0)
		{
			write (1, "-", 1);
			n *= -1;
		}
		i = 1;
		while (n / i >= 10)
			i *= 10;
		while (i)
		{
			s = n / i + '0';
			write (1, &s, 1);
			n %= i;
			i /= 10;
		}
	}
}

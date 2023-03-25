/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:07:36 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/20 12:51:31 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_sendsignal(int pid, char *str)
{
	int	i;
	int	j;

	j = 0;
	while (str[j] != '\0')
	{
		i = 7;
		while (i >= 0)
		{
			if (((str[j] >> i) & 1) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			i--;
		}
		j++;
	}
}

int	ft_getpid(char *str)
{
	int	pid;
	int	i;

	pid = 0;
	i = 0;
	while (str[i])
	{
		pid *= 10;
		pid += (str[i] - '0') % 10;
		i++;
	}
	return (pid);
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_getpid(argv[1]);
		ft_sendsignal(pid, argv[2]);
	}
	return (0);
}

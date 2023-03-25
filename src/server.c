/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:08:17 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/17 17:11:34 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_copy_bit(int sig)
{	
	static char	ch;
	static int	i;

	if (sig == SIGUSR1)
		ch = ch | 1;
	if (i != 7)
		ch = ch << 1;
	if (i++ == 7)
	{
		if (ch < 0 || ch > 127)
			exit (1);
		write (1, &ch, 1);
		ch = 0;
		i = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write (1, "\n", 1);
	signal(SIGUSR1, ft_copy_bit);
	signal(SIGUSR2, ft_copy_bit);
	while (1)
	{
		pause();
	}
	return (0);
}

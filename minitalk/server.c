/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkocak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:32:45 by ahkocak           #+#    #+#             */
/*   Updated: 2022/08/03 14:18:10 by ahkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal)
{
	static int	c = 0;
	static int	i = 128;

	if (signal == SIGUSR1)
		c = c | i;
	i = i / 2;
	if (i == 0)
	{
		ft_printf("%c", c);
		i = 128;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("Your server PID: %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkocak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:56:13 by ahkocak           #+#    #+#             */
/*   Updated: 2022/08/03 14:20:21 by ahkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	int	pid;
	int	bit;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (*argv[2])
		{
			bit = 7;
			while (bit >= 0)
			{
				if (*argv[2] >> bit & 1)
					kill(pid, SIGUSR1);
				else
					kill(pid, SIGUSR2);
				usleep(100);
				bit--;
			}
			argv[2]++;
		}
	}
	else
		ft_printf("[ERROR]: Please enter only 3 arguments.\n");
}

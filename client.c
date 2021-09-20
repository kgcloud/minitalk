/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:49:54 by canjugun          #+#    #+#             */
/*   Updated: 2021/09/20 18:56:03 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_letter(int pid, unsigned char letter, int i)
{
	while (i > -1)
	{
		if ((letter >> i) & 1)
		{	
			if (kill(pid, SIGUSR1) == -1)
				return (print("SIG1 -> wrong pid"));
		}
		else
		{	
			if (kill(pid, SIGUSR2) == -1)
				return (print("SIG2 -> wrong pid"));
		}
		i--;
		usleep(50);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	pid = ft_atoi(av[1]);
	if (ac != 3)
		return (print("./client <PID> <TEXT>"));
	while (av[2][i])
	{
		if (send_letter(pid, av[2][i], 7) == -1)
			return (0);
		i++;
	}
}

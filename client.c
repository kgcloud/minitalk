/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: KgCloud <KgCloud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:49:54 by canjugun          #+#    #+#             */
/*   Updated: 2021/09/16 14:48:03 by KgCloud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		send_letter(int pid, unsigned char letter, int i)
{
	printf("%d", pid);	
	while(i >=0)
	{
		if ((letter >> i) & 1)
			kill(pid, SIGUSR1); //a proteger
		else
			kill(pid, SIGUSR2); // a proteger
		i--;
	}
	return (0);
}

int     main(int ac, char **av)
{
    int	i;
	i = 0;
	if (ac != 3)
		return(printf("./client <PID> <TEXT>"));
	while (av[2][i])
	{
		send_letter(atoi(av[1]), av[2][i], 7); // a proteger
		i++;
	}
	
}
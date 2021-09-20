/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:13:02 by canjugun          #+#    #+#             */
/*   Updated: 2021/09/20 19:17:36 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

struct s_global	g_kg;

void	o_h(int sig)
{
	(void)sig;
	g_kg.c <<= 1;
	g_kg.c |= 1;
	g_kg.i++;
	if (g_kg.i % 8 == 0)
	{
		write(1, &g_kg.c, 1);
		g_kg.i = 0;
	}
}

void	z_s(int sig, siginfo_t *info, void *uap)
{
	(void)sig;
	(void)uap;
	(void)info;
	g_kg.c <<= 1;
	g_kg.i++;
	if (g_kg.i % 8 == 0 && g_kg.i != 0)
	{
		/*if (g_kg.c == '\0')
			kill(info->si_pid, SIGUSR1);
		else*/
		write(1, &g_kg.c, 1);
		g_kg.i = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	one;
	struct sigaction	zero;

	(void)ac;
	(void)av;
	one.sa_handler = o_h;
	zero.sa_sigaction = z_s;
	zero.sa_flags = SA_SIGINFO;
	g_kg.c = 0;
	g_kg.i = 0;
	print("my pid is :");
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		if (sigaction(SIGUSR1, &one, NULL) == -1)
			return (print("SIG1 -> impossible to perform an action"));
		if (sigaction(SIGUSR2, &zero, NULL) == -1)
			return (print("SIG2 -> impossible to perform an action"));
	}
	return (0);
}

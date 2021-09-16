/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: KgCloud <KgCloud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:48:34 by canjugun          #+#    #+#             */
/*   Updated: 2021/09/16 14:46:34 by KgCloud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

struct s_global     kg;

void    o_h(int sig)
{
    (void)sig;
    kg.c <<= 1;
    kg.c |= 1;
    kg.i++;
    if (kg.i % 8 == 0)
    {
        printf("%s", &kg.c);
        kg.i = 0;
    }
}

void    z_s(int sig, siginfo_t *info, void *uap)
{
    (void)sig;
    (void)uap;
    (void)info;
    kg.c <<= 1;
    kg.i++;
    if (kg.i % 8 == 0 && kg.i != 0)
    {
        printf("%s", &kg.c);
        kg.i = 0;
    }
}

int     main(int ac, char **av)
{
    struct sigaction    one;
    struct sigaction    zero;
    
    if (ac != 1)
        (void)av;
    one.sa_handler = o_h;
    zero.sa_sigaction = z_s;
    zero.sa_flags = SA_SIGINFO;
    printf("%d\n", sigaction(SIGUSR1, &one, NULL)); // a proteger
    printf("%d\n", sigaction(SIGUSR2, &zero, NULL)); // a proteger 
    kg.c = 0;
    kg.i = 0;
    printf("%d\n", getpid());
    while(1)
    {
    }
}
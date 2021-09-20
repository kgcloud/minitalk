/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canjugun <canjugun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:21:33 by canjugun          #+#    #+#             */
/*   Updated: 2021/09/20 19:21:40 by canjugun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>

struct s_global
{
	char	c;
	int		i;
};

int		main(int ac, char **av);
int		send_letter(int pid, unsigned char letter, int i);
void	z_s(int sig, siginfo_t *info, void *uap);
void	o_h(int sig);
int		print(char *str);
int		ft_atoi(const char *str);
void	ft_putnbr(int nb);
void	ft_putchar(char c);

#endif
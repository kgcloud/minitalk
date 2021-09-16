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


int     main(int ac, char **av);
int		send_letter(int pid, unsigned char letter, int i);

#endif
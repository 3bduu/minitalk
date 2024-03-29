/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:57:09 by abenlahb          #+#    #+#             */
/*   Updated: 2023/02/18 10:02:45 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfile.h"

void	signal_handler(int sig)
{
	static unsigned char	c;
	static int				shift;

	if (sig == SIGUSR1)
		c += 1 << (7 - shift);
	shift++;
	if (shift == 8)
	{
		shift = 0;
		write(1, &c, 1);
		if (c == '\0')
			write(1, "\n", 1);
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	pid = getpid();
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	ft_printf("The Server PID is :");
	ft_printf("%d\n", pid);
	while (1)
		pause();
	return (0);
}

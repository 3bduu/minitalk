/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:39:49 by abenlahb          #+#    #+#             */
/*   Updated: 2023/02/18 10:53:16 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headerfile.h"

void	signal_handler(int sig, siginfo_t *info, void *other)
{
	static unsigned char	c;
	static int				shift;

	(void)other;
	if (sig == SIGUSR1)
		c += 1 << (7 - shift);
	shift++;
	if (shift == 8)
	{
		shift = 0;
		write(1, &c, 1);
		if (c == '\0')
		{
			kill(info->si_pid, SIGUSR2);
			write(1, "\n", 1);
		}
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;
	pid_t				pid;

	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = signal_handler;
	pid = getpid();
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	ft_printf("The Server PID is :");
	ft_printf("%d\n", pid);
	while (1)
		pause();
	return (0);
}

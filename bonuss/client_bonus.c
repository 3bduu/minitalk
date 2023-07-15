/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:39:51 by abenlahb          #+#    #+#             */
/*   Updated: 2023/02/18 10:55:08 by abenlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headerfile.h"

int	ft_atoi(const char *str)
{
	unsigned long long	result;
	int					signe;
	int					i;

	signe = 1;
	result = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		if (result > 9223372036854775807 && signe == -1)
			return (0);
		else if (result > 9223372036854775807 && signe == 1)
			return (-1);
		i++;
	}
	return ((int)result * signe);
}

void	signal_handler(int sig)
{
	if (sig == SIGUSR2)
	{
		ft_printf("Message received\n");
		exit(0);
	}
	usleep(100);
}

void	choise_signal(int pid, int shift, unsigned char c)
{
	if (shift > 0)
		choise_signal(pid, shift - 1, c / 2);
	if ((c % 2) == 1)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_printf("Signal 1 Error\n");
			exit(0);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_printf("Signal 2 Error\n");
			exit(0);
		}
	}
	usleep(100);
}

void	select_char(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		choise_signal(pid, 7, str[i]);
		i++;
	}
	choise_signal(pid, 7, str[i]);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Invalid format. Try: ./client + PID + Message\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid == -1)
	{
		ft_printf("Invalid PID\n");
		return (1);
	}
	if (argv[2][0] == '\0')
		return (0);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	select_char(pid, argv[2]);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:04:00 by ldermign          #+#    #+#             */
/*   Updated: 2021/10/27 10:19:42 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	end_sentence(int pid_srv)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(pid_srv, SIGUSR2);
		usleep(100);
		i++;
	}
}

void	convert_ascii_to_binary(char *str, int pid_srv)
{
	int	i;
	int	ltr_bnr;

	i = 0;
	while (str[i])
	{
		ltr_bnr = 7;
		while (ltr_bnr >= 0)
		{
			if ((str[i] >> ltr_bnr) & 1)
			{
				if (kill(pid_srv, SIGUSR1) == -1)
					exit (0);
			}
			else
			{
				if (kill(pid_srv, SIGUSR2) == -1)
					exit (0);
			}
			usleep(100);
			ltr_bnr--;
		}
		i++;
	}
	end_sentence(pid_srv);
}

int	main(int ac, char **av)
{
	int	pid_server;

	if (ac != 3)
	{
		ft_putstr("Wrong number of arguments.\n");
		return (0);
	}
	if (av[2] == '\0')
		return (0);
	pid_server = ft_atoi(av[1]);
	convert_ascii_to_binary(av[2], pid_server);
	return (0);
}

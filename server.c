/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:25:29 by ldermign          #+#    #+#             */
/*   Updated: 2021/10/25 11:56:46 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	binary_to_int(char *str)
{
	int	nbr;
	int	i;

	nbr = 0;
	i = 0;
	while (str[i])
	{
		nbr = 2 * nbr + (str[i] - '0');
		i++;
	}
	return (nbr);
}

char	*join_dst_and_buffer(char *dst, char *str, int c)
{
	char	*tmp;

	tmp = dst;
	dst = ft_strjoin(dst, str);
	free(tmp);
	ft_memset(str, '\0', BUFSIZ);
	if (c == 0)
	{
		ft_putstr(dst);
		ft_memset(dst, '\0', ft_strlen(dst));
	}
	return (dst);
}

void	return_binary(int sig)
{
	static char	*dst;
	static char	str[BUFSIZ];
	static char	buffer[9];
	static int	tab[2];
	int			c;

	buffer[8] = '\0';
	str[BUFSIZ - 1] = '\0';
	if (sig == SIGUSR1)
		buffer[tab[1]] = '1';
	else if (sig == SIGUSR2)
		buffer[tab[1]] = '0';
	tab[1]++;
	if (tab[1] == 8)
	{
		tab[1] = 0;
		c = binary_to_int(buffer);
		str[tab[0]++] = c;
	}
	if (tab[0] == BUFSIZ - 1 || c == 0)
	{
		dst = join_dst_and_buffer(dst, str, c);
		tab[0] = 0;
	}
}

int	main(void)
{
	int	pid_server;

	pid_server = getpid();
	ft_putstr("PID server = ");
	ft_putnbr(pid_server);
	write(1, "\n", 1);
	signal(SIGUSR1, return_binary);
	signal(SIGUSR2, return_binary);
	while (1)
		pause();
	return (0);
}

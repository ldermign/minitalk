/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:52:48 by ldermign          #+#    #+#             */
/*   Updated: 2021/10/25 10:53:31 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*ft_memset(void *str, int c, size_t len)
{
	int		i;
	char	*s;

	i = 0;
	s = str;
	while (len > 0)
	{
		s[i] = (unsigned char)c;
		i++;
		len--;
	}
	return (str);
}

void	ft_putnbr(int nb)
{
	long	nbr;
	int		cara;

	nbr = nb;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		cara = nbr + '0';
		write(1, &(cara), 1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndresga <andresga@student.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:52:35 by ndresga           #+#    #+#             */
/*   Updated: 2024/10/03 11:52:35 by ndresga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "utils.h"

int	ft_atoi(const char *str)
{
	int	c;
	int	x;
	int	neg;

	x = 0;
	c = 0;
	neg = 1;
	while ((str[c] >= 9 && str[c] <= 13) || str[c] == 32)
		c++;
	if ((str[c] == '-' || str[c] == '+'))
	{
		if (str[c] == '-')
			neg *= -1;
		c++;
	}
	while ((str[c] >= '0' && str[c] <= '9'))
	{
		x = x * 10 + (str[c] - '0');
		c++;
	}
	return (x * neg);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb == 2147483647)
		write(1, "2147483647", 10);
	else
	{
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
			ft_putchar(nb % 10 + '0');
		}
		if (nb < 0)
		{
			ft_putchar('-');
			ft_putnbr(-nb);
		}
		else if (nb < 10)
		{
			ft_putchar(nb + '0');
		}
	}
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

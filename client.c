/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndresga <andresga@student.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:53:44 by ndresga           #+#    #+#             */
/*   Updated: 2024/10/03 11:53:44 by ndresga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "utils.h"

void	send_char(int pid, char c)
{
	int	i;
	int	result;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
			result = kill(pid, SIGUSR2);
		else
			result = kill(pid, SIGUSR1);
		if (result == -1)
		{
			ft_putstr("Error: Failed to send signal\n");
			exit(1);
		}
		usleep(500);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	if (argc != 3)
	{
		ft_putstr("Usage: ./client [PID] [message]\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	while (*message)
	{
		send_char(pid, *message);
		message++;
	}
	return (0);
}

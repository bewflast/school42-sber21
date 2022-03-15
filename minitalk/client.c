/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:57:00 by lwendi            #+#    #+#             */
/*   Updated: 2022/03/11 19:58:11 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	res;

	i = 0;
	n = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -n;
		i++;
	}
	while (str[i] >= '0' && str [i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * n);
}

static void	send_char(char c, int pid)
{
	int	i;

	i = 128;
	while (i >= 1)
	{
		if (i & c)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i /= 2;
	}
}

static void	send_string(char *message, int pid)
{
	int	n;

	n = -1;
	while (*(message + ++n))
		send_char(*(message + n), pid);
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc != 3)
		exit(EXIT_FAILURE);
	pid = (int)ft_atoi(argv[1]);
	send_string(argv[2], pid);
	exit(EXIT_SUCCESS);
}

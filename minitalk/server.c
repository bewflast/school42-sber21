/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:58:26 by lwendi            #+#    #+#             */
/*   Updated: 2022/03/11 19:59:53 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	nb[10];
	int		i;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (!n)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
		write(fd, "-", 1);
	n = (n < 0) * (-n) + n * (n >= 0);
	i = 0;
	while (n)
	{
		nb[i++] = (char)(48 + (n % 10));
		n /= 10;
	}
	while (i--)
		write(fd, &nb[i], 1);
}

static void	handle_signal(int signum)
{
	static int	char_to_out = 0;
	static int	bit = 128;

	if (signum == SIGUSR1)
		char_to_out += bit;
	bit /= 2;
	if (!bit)
	{
		write(1, &char_to_out, 1);
		bit = 128;
		char_to_out = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	write(1, "\nPID: ", 7);
	ft_putnbr_fd(getpid(), 0);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}

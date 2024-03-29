/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:10:30 by lwendi            #+#    #+#             */
/*   Updated: 2021/10/13 15:12:32 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

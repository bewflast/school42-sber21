/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:36:14 by lwendi            #+#    #+#             */
/*   Updated: 2022/01/14 17:00:28 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	size_t	strl;

	strl = 0;
	while (*(s + strl))
		strl++;
	return (strl);
}

static void	ft_putstr(char *str, char c)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	if (c == 'p')
		write (1, "0x", 2);
	i--;
	while (i >= 0)
		write (1, (str + i--), 1);
}

static int	ft_putnbr_base(unsigned long long nbr, char *base, char c)
{
	int					i;
	char				str[32];
	unsigned long long	num;

	i = 0;
	num = nbr;
	if (num < 0)
		num = num * (-1);
	while (num >= 16)
	{
		str[i] = base[num % 16];
		num = num / 16;
		i++;
	}
	str[i] = base[num];
	str[i + 1] = '\0';
	ft_putstr(str, c);
	return (ft_strlen(str));
}

int	ft_print_p(void *ptr, char c)
{
	unsigned long long	i;

	i = (unsigned long long) ptr;
	return (ft_putnbr_base(i, "0123456789abcdef", c) + 2);
}

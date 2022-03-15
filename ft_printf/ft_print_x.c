/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:36:30 by lwendi            #+#    #+#             */
/*   Updated: 2022/01/14 17:00:34 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static void	ft_putstr(char *str, char c)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	if (c == 'p')
		write (1, "0x", 2);
	i--;
	while (i >= 0)
		write (1, (str + i--), 1);
}

static int	count_base(char *base)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (*(base + i))
	{
		count++;
		i++;
	}
	return (count);
}

static int	ft_putnbr_base(unsigned int nbr, char *base, char c)
{
	int				i;
	char			str[32];
	unsigned int	count;
	unsigned int	num;

	i = 0;
	num = nbr;
	count = count_base(base);
	if (num < 0)
		num = num * (-1);
	while (num >= count)
	{
		str[i] = base[num % count];
		num = num / count;
		i++;
	}
	str[i] = base[num];
	str[i + 1] = '\0';
	ft_putstr(str, c);
	return (ft_strlen(str));
}

int	ft_print_x(unsigned int ptr, char c)
{
	unsigned int	i;

	i = ptr;
	if (c == 'x')
		return (ft_putnbr_base(i, "0123456789abcdef", c));
	else
		return (ft_putnbr_base(i, "0123456789ABCDEF", c));
}

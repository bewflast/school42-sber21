/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:09:43 by lwendi            #+#    #+#             */
/*   Updated: 2021/10/13 15:12:49 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cmmi(int num, char **tg)
{
	if (num == -2147483648)
	{
		*tg = ft_strdup("-2147483648");
		return (1);
	}
	else
		return (0);
}

static int	getnumlen(int num)
{
	int	res;

	res = 1;
	while (num / 10)
	{
		res++;
		num /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		snus;
	int		nl;
	int		i;

	result = NULL;
	if (cmmi(n, &result))
		return (result);
	snus = n < 0;
	n = (n < 0) * (-n) + n * (n >= 0);
	nl = getnumlen(n);
	result = (char *)malloc(nl + 1 + snus);
	if (!result)
		return (NULL);
	if (snus)
		*result = '-';
	i = nl - 1 + snus ;
	while (i >= snus)
	{
		*(result + i--) = (char)(48 + (n % 10));
		n /= 10;
	}
	*(result + snus + nl) = '\0';
	return (result);
}

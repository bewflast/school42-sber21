/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:36:06 by lwendi            #+#    #+#             */
/*   Updated: 2022/01/14 16:57:19 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	size_t	strl;

	strl = 0;
	while (*(s + strl))
		strl++;
	return (strl);
}

static char	*ft_strdup(const char *s1)
{
	char	*result;
	char	*temp;
	size_t	i;

	temp = (char *)malloc(ft_strlen(s1) + 1);
	i = 0;
	if (!temp)
		return (NULL);
	result = temp;
	while (*s1)
		*temp++ = *s1++;
	*temp = '\0';
	return (result);
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

static char	*ft_itoa(int n)
{
	char	*result;
	int		snus;
	int		nl;
	int		i;

	result = NULL;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
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

int	ft_print_d(int n)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa(n);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	free(str);
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:08:18 by lwendi            #+#    #+#             */
/*   Updated: 2021/10/13 15:08:46 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pow_ten(int n)
{
	int	res;

	res = 1;
	while (n--)
		res *= 10;
	return (res);
}

static int	cmm(const char *str)
{
	if (!ft_strncmp(str, "2147483647", 10)
		|| !ft_strncmp(str, "-2147483648", 11))
		return ((!ft_strncmp(str, "2147483647", 10)) * 2147483647
			+ (!ft_strncmp(str, "-2147483648", 11)) *(-2147483648));
	else
		return (0);
}

static int	issp(char c)
{
	return (c == ' ' || c == '\t'
		|| c == '\n' || c == '\v' || c == '\f' || c == '\r' );
}

int	ft_atoi(const char *str)
{
	char	sign;
	char	*pos;
	int		result;
	short	numlen;

	while (*str && issp(*str))
		str++;
	if ((*str == '+' || *str == '-') && !ft_isdigit(*(str + 1)))
		return (0);
	if (cmm(str))
		return (cmm(str));
	result = 0;
	sign = *str;
	str += 1 *((*str == '+' || *str == '-'));
	numlen = 0;
	pos = (char *)str;
	while (*str && ft_isdigit(*str++))
		numlen++;
	str = (const char *)pos;
	while (ft_isdigit(*pos))
	{
		result += ((int)(*pos - '0')) * pow_ten(str + numlen - pos - 1);
		pos++;
	}
	return (result *(-1) *(sign == '-') + result *(sign != '-'));
}

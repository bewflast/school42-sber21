/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:40:59 by lwendi            #+#    #+#             */
/*   Updated: 2022/02/26 22:30:04 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi.h"

int	ft_isdigit(char a)
{
	return ((int)a > 47 && (int)a < 58);
}

int	issp(char c)
{
	return (c == ' ' || c == '\t'
		|| c == '\n' || c == '\v' || c == '\f' || c == '\r' );
}

int	pow_ten(int n)
{
	int	res;

	res = 1;
	while (n--)
		res *= 10;
	return (res);
}

long long	ft_atoi(const char *str)
{
	char			sign;
	char			*pos;
	long long		result;
	short			numlen;

	while (*str && issp(*str))
		str++;
	if ((*str == '+' || *str == '-') && !ft_isdigit(*(str + 1)))
		return (-2147483649);
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
	if (result > 2147483648 || !numlen || *pos != '\0')
		return (-2147483649);
	return (result *(-1) *(sign == '-') + result *(sign != '-'));
}

int	is_valid(long long num)
{
	return (num > -2147483649 && num < 2147483648);
}

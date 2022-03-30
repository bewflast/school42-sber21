/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:11:04 by lwendi            #+#    #+#             */
/*   Updated: 2021/10/13 19:00:05 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	istrimsym(char c, char const *trs)
{
	size_t	i;

	i = -1;
	while (*(trs + ++i))
		if (*(trs + i) == c)
			return (1);
	return (0);
}

static int	checksets(const char *_s1, char const *_set, char **res, int nl)
{
	if (!*_set)
	{
		*res = ft_strdup(_s1);
		return (1);
	}
	if (!*_s1 || (int)nl <= 0)
	{
		*res = ft_strdup("");
		return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	from;
	size_t	to;
	size_t	i;
	char	*result;
	int		newlen;

	if (!s1)
		return (NULL);
	to = ft_strlen(s1) - 1;
	from = 0;
	i = 0;
	while (istrimsym(*(s1 + from), set))
		from++;
	while (istrimsym(*(s1 + to), set))
		to--;
	newlen = to - from + 1;
	if (checksets(s1, set, &result, newlen))
		return (result);
	result = (char *)malloc(newlen + 1);
	if (!result)
		return (NULL);
	while (from <= to)
		*(result + i++) = *(s1 + from++);
	*(result + i) = '\0';
	return (result);
}

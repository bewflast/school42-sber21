/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:10:35 by lwendi            #+#    #+#             */
/*   Updated: 2021/10/13 22:13:46 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_strs_count(char const *str, char _c)
{
	size_t	result;
	size_t	i;

	i = 0;
	result = 0;
	while (*(str + i))
	{
		while (*(str + i) == _c)
			i++;
		if (i == ft_strlen(str))
			break ;
		while (*(str + i) != _c && *(str + i))
			i++;
		result++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	j;
	size_t	n;

	result = (char **)malloc((get_strs_count(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	n = 0;
	while (*(s + i))
	{
		while (*(s + i) == c)
			i++;
		if (i == ft_strlen(s))
			break ;
		j = i;
		while (*(s + j) != c && *(s + j))
			j++;
		*(result + n++) = ft_substr(s, (unsigned int)i, j - i);
		i = j;
	}
	*(result + n) = NULL;
	return (result);
}

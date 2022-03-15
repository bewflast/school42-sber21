/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:29:20 by lwendi            #+#    #+#             */
/*   Updated: 2022/01/05 19:24:55 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	strl;

	strl = 0;
	while (*(s + strl))
		strl++;
	return (strl);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	t;
	size_t	i;
	char	*newstr;

	t = 0;
	i = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		*s1 = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	newstr = malloc(sizeof(*s1) * ((ft_strlen(s1)) + (ft_strlen(s2)) + 1));
	if (!newstr)
		return (NULL);
	while (*(s1 + i))
		*(newstr + t++) = *(s1 + i++);
	i = 0;
	while (*(s2 + i))
		*(newstr + t++) = *(s2 + i++);
	*(newstr + t) = '\0';
	free(s1);
	return (newstr);
}

char	*ft_result_line(char *line)
{
	int		i;
	char	*str;

	i = 0;
	if (!*(line + i))
		return (NULL);
	while (*(line + i) && *(line + i) != '\n')
		i++;
	str = malloc(sizeof(char) * i + 2);
	if (!str)
		return (NULL);
	i = -1;
	while (*(line + ++i) && *(line + i) != '\n')
		*(str + i) = *(line + i);
	if (*(line + i) == '\n')
	{
		*(str + i) = *(line + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

char	*ft_get_rmd(char *rmd)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (*(rmd + i) && *(rmd + i) != '\n')
		i++;
	if (!*(rmd + i))
	{
		free(rmd);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(rmd) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (*(rmd + i))
		*(str + j++) = *(rmd + i++);
	*(str + j) = '\0';
	free(rmd);
	return (str);
}

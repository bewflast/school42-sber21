/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:29:15 by lwendi            #+#    #+#             */
/*   Updated: 2022/01/05 19:24:59 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_n(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (*(str + i))
		if (*(str + i++) == '\n')
			return (1);
	return (0);
}

static char	*ft_find_str(int fd, char *line)
{
	char	*buffer;
	int		flag;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	flag = 1;
	while (!find_n(line) && flag)
	{	
		flag = read(fd, buffer, BUFFER_SIZE);
		if (flag == -1)
		{
			free(buffer);
			return (NULL);
		}
		*(buffer + flag) = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rmd;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rmd = ft_find_str(fd, rmd);
	if (!rmd)
		return (NULL);
	line = ft_result_line(rmd);
	rmd = ft_get_rmd(rmd);
	return (line);
}

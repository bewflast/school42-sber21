/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:10:40 by lwendi            #+#    #+#             */
/*   Updated: 2021/10/13 22:09:42 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
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

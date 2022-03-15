/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:11:08 by lwendi            #+#    #+#             */
/*   Updated: 2021/10/13 19:21:46 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	malloc_size;

	if (!s)
		return (NULL);
	if (!ft_strncmp(s, "", 1) || start > (unsigned int) ft_strlen(s))
	{
		result = ft_strdup("");
		return (result);
	}
	malloc_size = (len > ft_strlen(s)) * ft_strlen(s) \
	+ (len <= ft_strlen(s)) * len;
	result = (char *)malloc((malloc_size + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s + start, len + 1);
	return (result);
}

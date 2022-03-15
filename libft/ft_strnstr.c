/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:10:58 by lwendi            #+#    #+#             */
/*   Updated: 2021/10/13 15:12:13 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hst;

	hst = (char *)haystack;
	if (!ft_strncmp(needle, "", 1))
		return (hst);
	while (len && *hst)
	{
		if (*hst == *needle && !ft_strncmp(hst, needle, ft_strlen(needle)) \
		&& len >= ft_strlen(needle))
			return (hst);
		hst++;
		len--;
	}
	return (NULL);
}

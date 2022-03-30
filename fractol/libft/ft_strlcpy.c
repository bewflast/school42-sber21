/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:10:50 by lwendi            #+#    #+#             */
/*   Updated: 2021/10/13 19:20:50 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srl;
	size_t	i;

	i = -1;
	srl = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (!dstsize)
		return (srl);
	while (*(src + ++i) && i < dstsize)
		*(dst + i) = *(src + i);
	i = (dstsize <= srl) * (dstsize - 1) + (dstsize > srl) * i;
	*(dst + i) = '\0';
	return (srl);
}

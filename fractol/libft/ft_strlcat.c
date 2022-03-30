/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:10:46 by lwendi            #+#    #+#             */
/*   Updated: 2021/10/13 15:12:27 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	insert_pos;
	size_t	dl;
	size_t	i;

	dl = ft_strlen(dst);
	insert_pos = dl;
	i = 0;
	if (dl < dstsize - 1 && dstsize > 0)
	{
		while (*(src + i) && (insert_pos < dstsize - 1))
			*(dst + insert_pos++) = *(src + i++);
		*(dst + insert_pos) = '\0';
	}
	dl = dstsize * (dl >= dstsize) + dl * (dl < dstsize);
	return (dl + ft_strlen(src));
}

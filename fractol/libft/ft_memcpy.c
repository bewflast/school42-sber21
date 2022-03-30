/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:10:15 by lwendi            #+#    #+#             */
/*   Updated: 2021/10/13 15:12:36 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*startpos;

	if (!dst && !src)
		return (NULL);
	startpos = dst;
	while (n--)
		*((char *)dst++) = *((char *)src++);
	return (startpos);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:10:17 by lwendi            #+#    #+#             */
/*   Updated: 2021/10/13 15:12:35 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*startpos;

	startpos = dst;
	if (src < dst)
	{
		src += len - 1;
		dst += len - 1;
		while (len--)
			*(char *)dst-- = *(char *)src--;
	}
	else if (src > dst)
	{
		while (len--)
			*(char *)dst++ = *(char *)src++;
	}
	return (startpos);
}

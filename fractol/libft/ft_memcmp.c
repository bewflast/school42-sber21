/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:10:12 by lwendi            #+#    #+#             */
/*   Updated: 2021/10/13 15:12:37 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (--n && *(unsigned char *)(s1 + i) == *(unsigned char *)(s2 + i))
		i++;
	return ((*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i)) \
	* ((int)n != -1));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:10:38 by lwendi            #+#    #+#             */
/*   Updated: 2021/10/13 15:11:59 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	pos;

	pos = -1;
	while (*(++pos + s))
		if (*(s + pos) == (char)c)
			break ;
	if (*(s + pos) == (char)c)
		return ((char *)s + pos);
	else
		return (NULL);
}

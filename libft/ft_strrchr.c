/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:11:00 by lwendi            #+#    #+#             */
/*   Updated: 2021/10/13 15:12:11 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*pos ;

	pos = (char *) s + ft_strlen(s);
	if ((char)c == '\0')
		return (pos);
	while (pos-- > s)
		if (*pos == (char)c)
			return (pos);
	return (NULL);
}

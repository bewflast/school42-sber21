/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:10:54 by lwendi            #+#    #+#             */
/*   Updated: 2021/10/13 22:06:05 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	if (!s)
		return (NULL);
	result = ft_strdup(s);
	if (!result)
		return (NULL);
	i = -1;
	while (*(result + ++i))
		*(result + i) = f(i, *(result + i));
	return (result);
}

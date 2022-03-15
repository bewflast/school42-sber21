/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:10:07 by lwendi            #+#    #+#             */
/*   Updated: 2021/10/13 15:12:39 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	size_t	i;

	i = 1;
	if (!lst)
		return (0);
	if (!lst->next)
		return (i);
	temp = lst;
	while (temp->next)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

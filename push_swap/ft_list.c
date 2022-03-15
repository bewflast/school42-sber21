/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:41:50 by lwendi            #+#    #+#             */
/*   Updated: 2022/03/03 22:13:36 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lstnew(int data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = data;
	node->next = NULL;
	node->index = 0;
	return (node);
}

t_list	*ft_lstlast(t_list	*lst)
{
	t_list	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next)
		last = last->next;
	return (last);
}

t_list	*ft_lstprelast(t_list *lst)
{
	t_list	*prelast;

	if (!lst)
		return (NULL);
	prelast = lst;
	if (!prelast->next)
		return (prelast);
	while ((prelast->next)->next)
		prelast = prelast->next;
	return (prelast);
}

void	ft_lstclear(t_list *lst)
{
	if ((lst)->next)
		ft_lstclear((lst)->next);
	free(lst);
}

int	is_duplicated(int data, t_list *lst)
{
	t_list	*begin;

	begin = lst;
	if (!lst)
		return (0);
	while ((lst)->next)
	{
		if ((lst)->content == data)
		{
			lst = begin;
			return (1);
		}
		lst = (lst)->next;
	}
	if ((lst)->content == data)
		return (1);
	lst = begin;
	return (0);
}

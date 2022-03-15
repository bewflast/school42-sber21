/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:09:52 by lwendi            #+#    #+#             */
/*   Updated: 2021/10/13 15:12:46 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rec_del(t_list *node, void (*d)(void*))
{
	if (node->next)
		ft_rec_del(node->next, d);
	ft_lstdelone(node, d);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	ft_rec_del(*lst, del);
	*lst = NULL;
}

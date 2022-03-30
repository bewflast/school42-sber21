/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:09:57 by lwendi            #+#    #+#             */
/*   Updated: 2021/10/13 15:12:43 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_apply_f(t_list *node, void (*_f)(void *))
{
	if (node->next)
		ft_apply_f(node->next, _f);
	_f(node->content);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	ft_apply_f(lst, f);
}

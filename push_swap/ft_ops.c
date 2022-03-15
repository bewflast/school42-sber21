/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:40:40 by lwendi            #+#    #+#             */
/*   Updated: 2022/03/04 20:32:46 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_s(t_stack *st, int trace)
{
	int		data;
	int		index;

	if (!st->list)
		return ;
	if (!st->list->next)
		return ;
	data = st->list->content;
	index = st->list->index;
	st->list->content = st->list->next->content;
	st->list->next->content = data;
	st->list->index = st->list->next->index;
	st->list->next->index = index;
	if (trace)
	{
		write(1, "s", 1);
		write(1, &st->id, 1);
		write(1, "\n", 1);
	}
}

void	ft_p(t_stack *a, t_stack *b, int trace)
{
	t_list	*popped;

	if (!b->list)
		return ;
	popped = b->pop(b);
	popped->next = a->list;
	a->list = popped;
	if (trace)
	{
		write(1, "p", 1);
		write(1, &a->id, 1);
		write(1, "\n", 1);
	}
}

void	ft_r(t_stack *stack, int trace)
{
	t_list	*head;

	if (!stack->list || !stack->list->next)
		return ;
	head = stack->list;
	ft_lstlast(stack->list)->next = head;
	stack->list = head->next;
	head->next = NULL;
	if (trace)
	{
		write(1, "r", 1);
		write(1, &stack->id, 1);
		write(1, "\n", 1);
	}
}

void	ft_rr(t_stack *stack, int trace)
{
	t_list	*prelast;
	t_list	*last;

	if (!stack->list || !stack->list->next)
		return ;
	prelast = ft_lstprelast(stack->list);
	last = ft_lstlast(stack->list);
	last->next = stack->list;
	stack->list = last;
	prelast->next = NULL;
	if (trace)
	{
		write(1, "rr", 2);
		write(1, &stack->id, 1);
		write(1, "\n", 1);
	}
}

void	ft_both(t_stack *a, t_stack *b, int op)
{
	if ((char)op == 's')
	{
		ft_s(a, 0);
		ft_s(b, 0);
		return ;
	}
	if ((char)op == 'r')
	{
		ft_r(a, 0);
		ft_r(b, 0);
		return ;
	}
	if ((char)op == 't')
	{
		ft_rr(a, 0);
		ft_rr(b, 0);
		return ;
	}
}

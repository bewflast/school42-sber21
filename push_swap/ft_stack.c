/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:41:30 by lwendi            #+#    #+#             */
/*   Updated: 2022/03/03 22:43:13 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_ops.h"

void	s_push(t_stack *stack, t_list *data)
{
	t_list	**list;
	t_list	*last;

	if (!data)
		return ;
	list = &(stack->list);
	if (!*list)
	{
		*list = data;
		return ;
	}
	last = ft_lstlast(*list);
	last->next = data;
	data->next = NULL;
	if (last->content > data->content)
		stack->sorted = -1;
}

t_list	*s_pop(t_stack *stack)
{
	t_list	*result;

	if (!stack->list)
		return (NULL);
	result = stack->list;
	stack->list = stack->list->next;
	return (result);
}

void	ft_clear_stack(t_stack *stack)
{
	if (stack->list)
		ft_lstclear(stack->list);
	free(stack);
}

t_stack	*new_stack(char **nums, int size, char id)
{
	int			i;
	t_stack		*stack;
	long long	num;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->list = NULL;
	stack->push = s_push;
	stack->pop = s_pop;
	stack->id = id;
	stack->sorted = 1;
	i = 1;
	while (i < size)
	{
		num = ft_atoi(*(nums + i++));
		if (!is_valid(num) || is_duplicated(num, stack->list))
		{
			write(2, "Error\n", 6);
			ft_clear_stack(stack);
			exit(EXIT_FAILURE);
		}
		stack->push(stack, ft_lstnew((int)num));
	}
	return (stack);
}

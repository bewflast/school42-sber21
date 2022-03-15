/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:22:56 by lwendi            #+#    #+#             */
/*   Updated: 2022/03/03 22:44:31 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sorts.h"

void	pick_sort(t_stack *a, t_stack *b, int argc)
{
	if (argc == 3)
		ft_s(a, 1);
	else if (argc == 4)
		sort_3(a, b);
	else if (argc <= 6)
		sort_5(a, b, argc);
	else
		sort_100500(a, b, argc, (argc <= 101) * 15 + (argc > 102) * 30);
	exit(EXIT_SUCCESS);
}

void	ft_brawl_stars(int *array, int argc)
{
	int	tmp;
	int	i;
	int	j;

	i = -1;
	j = i;
	while (++i < (argc - 1))
	{
		while (++j < (argc - i - 1))
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
		j = -1;
	}
}

void	presort(t_stack *stack, int argc, char **argv)
{
	int		*temp;
	int		i;
	t_list	*head;

	head = stack->list;
	i = -1;
	temp = malloc(sizeof(int) * (argc - 1));
	while (++i < argc - 1)
		temp[i] = ft_atoi(*(argv + i + 1));
	ft_brawl_stars(temp, argc - 1);
	while (stack->list)
	{
		i = -1;
		while (++i < argc - 1)
		{
			if (temp[i] == stack->list->content)
			{
				stack->list->index = i;
				break ;
			}
		}
		stack->list = stack->list->next;
	}
	stack->list = head;
}

int	count_steps(t_list *lst)
{
	int	n;

	n = 0;
	while (lst)
	{
		n++;
		lst = lst->next;
	}
	return (n);
}

int	find_max(t_list **lst, int i)
{
	t_list	*tmp;
	int		n;

	n = 0;
	tmp = *lst;
	while (tmp)
	{
		if (tmp->index == i)
			break ;
		tmp = tmp->next;
		n++;
	}
	return (n);
}

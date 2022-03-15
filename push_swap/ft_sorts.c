/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:27:18 by lwendi            #+#    #+#             */
/*   Updated: 2022/03/03 22:39:22 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ops.h"
#include "ft_sorts_utils.h"

void	sort_u(t_stack *a, t_stack *b, int argc)
{
	int		max_i;
	int		half;
	int		place;
	t_list	**l1;

	l1 = &b->list;
	max_i = argc - 2;
	while (*l1)
	{
		half = (max_i + 1) / 2;
		place = find_max(l1, max_i);
		if ((*l1)->index == max_i)
		{
			ft_p(a, b, 1);
			max_i--;
		}
		else if (place <= half && (*l1)->index != max_i)
			ft_r(b, 1);
		else if (place > half && (*l1)->index != max_i)
			ft_rr(b, 1);
	}
}

void	sort_3(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->list->content;
	b = stack->list->next->content;
	c = stack->list->next->next->content;
	if (((a > b) && ((c > b && c > a) || (a > c && b > c)))
		|| (a < b && a < c && b > c))
		ft_s(stack, 1);
	if ((a < b && a < c && b > c) || (a > b && c > b && a > c))
		ft_r(stack, 1);
	if (((a > b) || (a < b)) && (a > c && b > c))
		ft_rr(stack, 1);
}

void	sort_5(t_stack *a, t_stack *b, int argc)
{
	t_list	*m_m;
	t_list	*prev;

	m_m = a->list;
	prev = m_m;
	while (count_steps(a->list) != 3)
	{
		m_m = m_m->next;
		if (!prev->index || prev->index == argc - 2)
			ft_p(b, a, 1);
		else
			ft_r(a, 1);
		prev = m_m;
	}
	sort_3(a);
	while (count_steps(b->list))
	{
		if (!b->list->index)
			ft_p(a, b, 1);
		else
		{
			ft_p(a, b, 1);
			ft_r(a, 1);
		}
	}
}

void	sort_100500(t_stack *a, t_stack *b, int argc, int chunks)
{
	int		i;
	t_list	**ac;

	ac = &a->list;
	i = 0;
	while (*ac)
	{
		if ((a->list->index <= i && i > 1))
		{
			ft_p(b, a, 1);
			ft_r(b, 1);
			i++;
		}
		else if (a->list->index <= (i + chunks))
		{
			ft_p(b, a, 1);
			i++;
		}
		else if (a->list->index >= i)
			ft_r(a, 1);
	}
	sort_u(a, b, argc);
}

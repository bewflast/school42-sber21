/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:21:25 by lwendi            #+#    #+#             */
/*   Updated: 2022/03/05 04:08:06 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "ft_stack.h"
#include "ft_sorts.h"

t_stack	*pick_target(char *op, t_stack *a, t_stack *b, int reverse)
{
	int	i;

	i = 0;
	while (*(op + i) != '\n')
		i++;
	if (op[i - 1] == 'a')
		if (reverse)
			return (b);
	else
		return (a);
	else
		if (reverse)
			return (a);
	else
		return (b);
}

int	op_is_valid(char *op)
{
	int	i;

	i = -1;
	while (*(op + ++i) != '\n')
	{
		if (op[i] != 'r' && op[i] != 's' && op[i] != 'a'
			&& op[i] != 'b' && op[i] != 'p')
			return (5);
	}
	if (i > 3 || !i || i == 1)
		return (5);
	if (i == 3 && op[i - 1] != 's')
		return ((op[i - 1] == 'r') * 4 + (op[i - 1] != 'r') * 2);
	else if ((op[0] == 's' && op[i - 1] == 's')
		|| (op[0] == 'r' && op[i - 1] == 'r'))
		return (4);
	else if (op[1] == 'a' || op[1] == 'b')
		return ((op[0] == 'r') + (op[0] == 'p') * 3);
	else
		return (5);
}

void	pick_op(char *op, t_stack *a, t_stack *b)
{
	static void	(*commands[5])() = {ft_s, ft_r, ft_rr, ft_p, ft_both};
	int			op_num;
	t_stack		*target;

	op_num = op_is_valid(op);
	if (op_num == 5)
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (op_num == 4)
		if (op[0] == 's')
			commands[4](a, b, 115);
	else if (op[0] == 'r' && op[2] == '\n')
		commands[4](a, b, 114);
	else
		commands[4](a, b, 116);
	else if (op[0] == 'p')
		commands[op_num](pick_target(op, a, b, 0), pick_target(op, a, b, 1), 0);
	else
		commands[op_num](pick_target(op, a, b, 0), 0);
}

int	validate_stack(t_stack *a, int size)
{
	t_list	*begin;
	int		i;

	i = 1;
	begin = a->list;
	while (begin->next)
	{
		if (begin->content > begin->next->content)
			return (0);
		begin = begin->next;
		i++;
	}
	return (i == size);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*op;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	a = new_stack(argv, argc, 'a');
	op = get_next_line(0);
	if (a->sorted == 1 && !op)
	{
		write(1, "OK\n", 3);
		exit(EXIT_SUCCESS);
	}
	b = new_stack(argv, 0, 'b');
	while (op)
	{
		pick_op(op, a, b);
		free(op);
		op = get_next_line(0);
	}
	if (!validate_stack(a, argc - 1))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	exit(EXIT_SUCCESS);
}

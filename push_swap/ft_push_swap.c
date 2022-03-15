/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:20:05 by lwendi            #+#    #+#             */
/*   Updated: 2022/03/03 22:44:41 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_sorts.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	a = new_stack(argv, argc, 'a');
	if (a->sorted == 1)
	{
		ft_clear_stack(a);
		exit(EXIT_SUCCESS);
	}
	b = new_stack(argv, 0, 'b');
	presort(a, argc, argv);
	pick_sort(a, b, argc);
	exit(EXIT_SUCCESS);
}

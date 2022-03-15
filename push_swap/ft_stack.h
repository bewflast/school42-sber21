/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:41:36 by lwendi            #+#    #+#             */
/*   Updated: 2022/03/03 22:31:02 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include "ft_list.h"

typedef struct s_stack
{
	void		(*push)(struct s_stack*, t_list*);
	t_list		*(*pop)(struct s_stack*);
	t_list		*list;
	char		id;
	int			sorted;
}	t_stack;

t_stack	*new_stack(char **nums, int size, char id);
void	ft_clear_stack(t_stack *stack);
#endif
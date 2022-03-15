/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:26:49 by lwendi            #+#    #+#             */
/*   Updated: 2022/03/03 22:27:03 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORTS_UTILS_H
# define FT_SORTS_UTILS_H

void	pick_sort(t_stack *a, t_stack *b, int argc);
void	ft_brawl_stars(int *array, int argc);
void	presort(t_stack *stack, int argc, char **argv);
int		count_steps(t_list *lst);
int		find_max(t_list **lst, int i);

#endif
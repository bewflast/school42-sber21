/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:40:45 by lwendi            #+#    #+#             */
/*   Updated: 2022/03/04 20:12:18 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPS_H
# define FT_OPS_H
# include "ft_stack.h"
# include "ft_atoi.h"

void	ft_s(t_stack *st, int trace);
void	ft_p(t_stack *a, t_stack *b, int trace);
void	ft_r(t_stack *stack, int trace);
void	ft_rr(t_stack *stack, int trace);
void	ft_both(t_stack *a, t_stack *b, int op);

#endif
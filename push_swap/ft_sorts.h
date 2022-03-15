/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:28:42 by lwendi            #+#    #+#             */
/*   Updated: 2022/03/03 22:28:43 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORTS_H
# define FT_SORTS_H

# include "ft_ops.h"
# include "ft_sorts_utils.h"

void	sort_3(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b, int argc);
void	sort_100500(t_stack *a, t_stack *b, int argc, int chunks);
void	sort_u(t_stack *a, t_stack *b, int argc);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:41:46 by lwendi            #+#    #+#             */
/*   Updated: 2022/03/02 16:04:33 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				index;
	int				content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(int data);
t_list	*ft_lstlast(t_list	*lst);
t_list	*ft_lstprelast(t_list *lst);
void	ft_lstclear(t_list *lst);
int		is_duplicated(int data, t_list *lst);

#endif
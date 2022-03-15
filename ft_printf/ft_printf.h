/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:36:38 by lwendi            #+#    #+#             */
/*   Updated: 2022/01/14 16:57:28 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdarg.h>
# include<unistd.h>
# include<stdlib.h>
# include<stddef.h>

int	ft_printf(const char *arg, ...);
int	ft_print_c(int c);
int	ft_print_str(char *str);
int	ft_print_d(int n);
int	ft_print_p(void *ptr, char c);
int	ft_print_u( unsigned int n);
int	ft_print_x(unsigned int ptr, char c);

#endif
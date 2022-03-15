/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:36:34 by lwendi            #+#    #+#             */
/*   Updated: 2022/01/14 16:57:26 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	ft_define_res(const char *arg, int i, va_list var, int res)
{
	if (arg[i] == '%' && arg[i + 1] == 'c')
		res += ft_print_c(va_arg(var, int));
	if (arg[i] == '%' && arg[i + 1] == 's')
		res += ft_print_str(va_arg(var, char *));
	if (arg[i] == '%' && arg[i + 1] == 'p')
		res += ft_print_p(va_arg(var, void *), arg[i + 1]);
	if (arg[i] == '%' && arg[i + 1] == 'd')
		res += ft_print_d(va_arg(var, int));
	if (arg[i] == '%' && arg[i + 1] == 'i')
		res += ft_print_d(va_arg(var, int));
	if (arg[i] == '%' && arg[i + 1] == 'u')
		res += ft_print_u(va_arg(var, unsigned int));
	if (arg[i] == '%' && (arg[i + 1] == 'x' || arg[i + 1] == 'X'))
		res += ft_print_x(va_arg(var, unsigned int), arg[i + 1]);
	if (arg[i] == '%' && arg[i + 1] == '%')
		res += ft_print_c('%');
	return (res);
}

int	ft_printf(const char *arg, ...)
{
	va_list	var;
	int		res;
	int		i;

	i = 0;
	res = 0;
	va_start(var, arg);
	while (arg[i])
	{
		if (arg[i] != '%')
		{
			write(1, &arg[i], 1);
			res++;
			i++;
		}
		else
		{
			res = ft_define_res(arg, i, var, res);
			i += 2;
		}
	}
	va_end(var);
	return (res);
}

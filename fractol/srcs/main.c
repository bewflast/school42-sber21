/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:37:02 by lwendi            #+#    #+#             */
/*   Updated: 2022/03/29 20:48:53 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	main(int argc, char **argv)
{
	t_mrt		*m_info;
	t_data		*par;
	static void	(*frac_draw_types[3])() = {draw_mandel, draw_jul, draw_bs};
	static char	*frac_names[3] = {"Mandelbrot", "Julia", "Burning Ship"};
	int			frac_num;

	m_info = init_mrt();
	frac_num = ft_validate(argc, argv, m_info);
	par = init_data(m_info, frac_names[frac_num]);
	par->pick_draw = frac_draw_types[frac_num];
	par->pick_draw(par, m_info);
	mlx_hook(par->mlx_window, 2, 0, keyhook, par);
	mlx_hook(par->mlx_window, 4, 0, mouse_handle, par);
	mlx_hook(par->mlx_window, 17, 0, leave, par);
	mlx_loop(par->mlx);
}

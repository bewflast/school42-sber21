/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 20:42:09 by lwendi            #+#    #+#             */
/*   Updated: 2022/03/29 21:22:47 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	loop_bs(t_mrt *info, int x, int y)
{
	long double	tr;
	long double	re;
	long double	im;
	int			it;

	re = 0;
	im = 0;
	it = -1;
	while (++it < info->max_iter && re * re + im * im < 4)
	{
		tr = re * re - im * im
			+ (info->min_re + (info->max_re - info->min_re) * x / W);
		im = fabsl(2 * re * im + (info->min_im
					+ (info->max_im - info->min_im) * y / H));
		re = fabsl(tr);
	}
	return (it);
}

void	draw_bs(t_data *data, t_mrt *info)
{
	int	x;
	int	y;
	int	it;

	x = -1;
	while (++x < W)
	{
		y = -1;
		while (++y < H)
			my_mlx_pixel_put(data, x, y,
				pick_color(data, loop_bs(info, x, y)));
	}
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->img, 0, 0);
}

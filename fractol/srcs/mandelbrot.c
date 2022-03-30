/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:09:38 by lwendi            #+#    #+#             */
/*   Updated: 2022/03/29 20:41:29 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

t_mrt	*init_mrt(void)
{
	t_mrt	*info;

	info = malloc(sizeof(t_mrt));
	info->max_iter = 128;
	info->min_re = -2.5;
	info->max_re = 1;
	info->min_im = -1;
	info->max_im = 1;
	info->cre = 0.285;
	info->cim = 0;
	return (info);
}

int	loop_draw(t_mrt *info, int x, int y)
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
		im = 2 * re * im + (info->min_im
				+ (info->max_im - info->min_im) * y / H);
		re = tr;
	}
	return (it);
}

void	draw_mandel(t_data *data, t_mrt *info)
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
				pick_color(data, loop_draw(info, x, y)));
	}
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->img, 0, 0);
}

void	zoom(int x, int y, double z, t_mrt *info)
{
	long double	cr;
	long double	ci;
	long double	tminr;
	long double	tmini;

	cr = info->min_re + (info->max_re - info->min_re) * x / W;
	ci = info->min_im + (info->max_im - info->min_im) * y / H;
	tminr = cr - (info->max_re - info->min_re) / z;
	info->max_re = cr + (info->max_re - info->min_re) / z;
	info->min_re = tminr;
	tmini = ci - (info->max_im - info->min_im) / z;
	info->max_im = ci + (info->max_im - info->min_im) / z;
	info->min_im = tmini;
}

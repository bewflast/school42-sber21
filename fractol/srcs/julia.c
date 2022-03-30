/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:41:00 by lwendi            #+#    #+#             */
/*   Updated: 2022/03/29 21:16:31 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	loop_drj(t_mrt *info, double x, double y)
{
	long double	tr;
	long double	re;
	long double	im;
	int			it;

	it = -1;
	while (++it < info->max_iter && x * x + y * y < 4)
	{
		re = x;
		im = y;
		x = re * re - im * im + info->cre;
		y = 2 * re * im + info->cim;
	}
	return (it);
}

void	draw_jul(t_data *data, t_mrt *info)
{
	double	x;
	double	y;
	double	a;
	double	b;
	int		it;

	x = -1;
	while (++x < W)
	{
		y = -1;
		while (++y < H)
			my_mlx_pixel_put(data, x, y,
				pick_color(data, loop_drj(info, info->min_re
						+(info->max_re - info->min_re)
						* x / W, info->min_im
						+(info->max_im - info->min_im) * y / H)));
	}
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->img, 0, 0);
}

void	validate_julia(t_mrt *info, int argc, char **argv)
{
	if (argc > 4)
	{
		write(1, "Too many argumets for Julia set!\n", 34);
		exit(EXIT_FAILURE);
	}
	if (argc == 2)
		write(1, "Missing c_re and c_im!\
		\nThey will be set as 0.285 and 0\n", 58);
	else
	{
		info->cre = ft_atod(argv[2]);
		if (argv[2][1] == '0' && argv[2][0] == '-')
			info->cre = info->cre * -1;
		if (argc == 3)
			write(1, "\nMissing c_im!\nIt will be set as 0\n", 35);
		else
		{
			info->cim = ft_atod(argv[3]);
			if (argv[3][1] == '0' && argv[3][0] == '-')
				info->cim = info->cim * -1;
		}
	}
}

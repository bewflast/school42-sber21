/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:00:18 by lwendi            #+#    #+#             */
/*   Updated: 2022/03/29 21:23:11 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

t_data	*init_data(t_mrt *info, char *fname)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->mlx = mlx_init();
	data->mlx_window = mlx_new_window(data->mlx, W, H, fname);
	data->img = mlx_new_image(data->mlx, W, H);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->info = info;
	data->c_schema = 1;
	return (data);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * data->bits_per_pixel / 8);
	*(unsigned int *)dst = color;
}

void	move_fr(int key, t_data *p)
{
	double	dw;
	double	dh;

	dw = (p->info->max_re - p->info->min_re) * MOVE_STEP;
	dh = (p->info->max_im - p->info->min_im) * MOVE_STEP;
	if (key == 123 || key == 124)
	{
		p->info->min_re = (key == 123) * (p->info->min_re - dw)
			+ (key == 124) * (p->info->min_re + dw);
		p->info->max_re = (key == 123) * (p->info->max_re - dw)
			+ (key == 124) * (p->info->max_re + dw);
	}
	if (key == 125 || key == 126)
	{
		p->info->min_im = (key == 125) * (p->info->min_im + dh)
			+ (key == 126) * (p->info->min_im - dh);
		p->info->max_im = (key == 125) * (p->info->max_im + dh)
			+(key == 126) * (p->info->max_im - dh);
	}
	p->pick_draw(p, p->info);
}

int	keyhook(int key, t_data *p)
{
	if (key == 53)
		leave(p);
	if (key >= 123 && key <= 126)
		move_fr(key, p);
	if (key == 8)
		shift_color(p);
	return (0);
}

int	mouse_handle(int button, int x, int y, t_data *par)
{
	if (button == 4)
		zoom(x, y, ZOOM_STEP + 1, par->info);
	if (button == 5)
		zoom(x, y, ZOOM_STEP + 2, par->info);
	if (button == 1 || button == 2)
		par->info->max_iter = (button == 1) * (par->info->max_iter * 2)
			+ (button == 2) * (par->info->max_iter / 2);
	if (button >= 1 && button <= 5 && button != 3)
		par->pick_draw(par, par->info);
	return (0);
}

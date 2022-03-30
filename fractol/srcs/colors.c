/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:30:38 by lwendi            #+#    #+#             */
/*   Updated: 2022/03/28 20:43:42 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	pick_color(t_data *data, int it)
{
	int	r;
	int	g;
	int	b;

	if (data->c_schema == 1)
	{
		r = it % 8 * 16;
		g = it % 4 * 32;
		b = it % 2 & 128;
	}
	if (data->c_schema == 2)
	{
		r = 1.0 * (data->info->max_iter - it) / data->info->max_iter * 0xff;
		g = r;
		b = r;
	}
	if (data->c_schema == 3)
	{
		r = 1.0 * (data->info->max_iter - it) / data->info->max_iter * 0xff;
		g = 2.0 * (data->info->max_iter - it) / data->info->max_iter * 0xff;
		b = 3.0 * (data->info->max_iter - it) / data->info->max_iter * 0xff;
	}
	return (create_trgb(0, r, g, b));
}

void	shift_color(t_data *p)
{
	p->c_schema++;
	if (p->c_schema > 3)
		p->c_schema = 1;
	p->pick_draw(p, p->info);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:36:10 by lwendi            #+#    #+#             */
/*   Updated: 2022/03/29 20:48:41 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	leave(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->mlx_window);
	free(data->info);
	free(data);
	exit(EXIT_SUCCESS);
}

void	prikol(double *res, double *frac, double *iint, char **spl)
{
	*frac = ft_atoi(spl[1]);
	*res = ((*iint < 0) * (*iint * -1) + (*iint >= 0) * *iint)
		+ (((*frac < 0) * (*frac * -1) + (*frac >= 0) * *frac)
			/ (pow(10, ft_strlen(spl[1])
					-(spl[1][0] == '+' || spl[1][0] == '-'))));
}

double	ft_atod(char *dstr)
{
	char	**spl;
	double	int_part;
	double	frac_part;
	int		spl_size;
	double	result;

	spl_size = 0;
	spl = ft_split(dstr, '.');
	while (*(spl + spl_size))
		spl_size++;
	if (!spl_size)
	{
		free(spl);
		return (0.0);
	}
	int_part = ft_atoi(spl[0]);
	if (spl_size == 1)
		result = int_part;
	else
		prikol(&result, &frac_part, &int_part, spl);
	spl_size--;
	while (spl_size >= 0)
		free(spl[spl_size--]);
	free(spl);
	return ((int_part < 0) * (result * -1) + (int_part >= 0) * result);
}

int	validate_args(int to_set, int argc, t_mrt *info, char **argv)
{
	if (!to_set && argc > 2)
	{
		write(1, "Too many argumets for Mandelbrot set!\n", 38);
		exit(EXIT_FAILURE);
	}
	if (to_set == 2 && argc > 2)
	{
		write(1, "Too many argumets for Burning Ship set!\n", 40);
		exit(EXIT_FAILURE);
	}
	if (to_set == 1)
		validate_julia(info, argc, argv);
	return (to_set);
}

int	ft_validate(int argc, char **argv, t_mrt *info)
{
	int	frac_num;

	frac_num = -1;
	if (argc == 1)
	{
		write(1, "No parameter is provided!\
		\nList of available parameters:\n\tMandelbrot\n\tJulia\
		\n\tBurningShip\n", 92);
		exit(EXIT_FAILURE);
	}
	if (!ft_strcmp(argv[1], "Mandelbrot"))
		frac_num = validate_args(0, argc, info, argv);
	else if (!ft_strcmp(argv[1], "Julia"))
		frac_num = validate_args(1, argc, info, argv);
	else if (!ft_strcmp(argv[1], "BurningShip"))
		frac_num = validate_args(2, argc, info, argv);
	if (frac_num == -1)
	{
		write(1, "Invalid fractol name!\
		\nList of available parameters:\
		\n\tMandelbrot\n\tJulia\n\tBurningShip\n", 88);
		exit(EXIT_FAILURE);
	}
	return (frac_num);
}

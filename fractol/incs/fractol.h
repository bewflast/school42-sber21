/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwendi <lwendi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:50:52 by lwendi            #+#    #+#             */
/*   Updated: 2022/03/29 21:22:21 by lwendi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include "../libft/libft.h"

# define ZOOM_STEP 0.5
# define MOVE_STEP 0.1
# define W 1920
# define H 1080

typedef struct s_mrt_info {
	long double	min_re;
	long double	max_re;
	long double	min_im;
	long double	max_im;
	int			max_iter;
	double		cre;
	double		cim;
}	t_mrt;

typedef struct s_data {
	void	*img;
	void	*mlx;
	void	*mlx_window;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		c_schema;
	t_mrt	*info;
	void	(*pick_draw)(struct s_data*, t_mrt*);
}	t_data;

double	ft_atod(char *dstr);
void	validate_julia(t_mrt *info, int argc, char **argv);
int		ft_validate(int argc, char **argv, t_mrt *info);
int		leave(t_data *data);
t_data	*init_data(t_mrt *info, char *fname);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
int		pick_color(t_data *data, int it);
void	shift_color(t_data *p);
void	move_fr(int key, t_data *p);
int		keyhook(int key, t_data *p);
int		mouse_handle(int button, int x, int y, t_data *par);

t_mrt	*init_mrt(void);
void	draw_mandel(t_data *data, t_mrt *info);
void	zoom(int x, int y, double z, t_mrt *info);
void	draw_jul(t_data *data, t_mrt *info);
int		loop_bs(t_mrt *info, int x, int y);
void	draw_bs(t_data *data, t_mrt *info);

#endif
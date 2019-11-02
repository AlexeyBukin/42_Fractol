/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:06:26 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/02 13:33:15 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <fcntl.h>

# define FRACT_BOUND_X  1024
# define FRACT_BOUND_Y  1024
# define FRACT_OFFSET_Y 128

# define WINDOW_BOUND_X  1024
# define WINDOW_BOUND_Y  1024

# define BOUND_X 1024
# define BOUND_Y 1024

# define ESC_KEY 	53
# define R_KEY   	15

# define MASK_RED   0x00FF0000
# define MASK_GREEN 0x0000FF00
# define MASK_BLUE  0x000000FF

# define FRACTAL_JULIA        1
# define FRACTAL_MONDELBROT   2

# define COMPLEX_ARG_REAL_DELTA 0.01
# define COMPLEX_ARG_IMG_DELTA  0.01

# define ITERATIONS_DELTA 1.3
# define SCALE_DELTA 1.3

# define COLOR_SCHEME_BW   1
# define COLOR_SCHEME_RGB  2
# define COLOR_SCHEME_NICE 3

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_adr;
	double			offset_x;
	double			offset_y;
	int				max_iters;
	double			scale;
	int				color_scheme;
	double			c_r;
	double			c_i;
	double			radius;
	int				fractal_id;
	int 			wheel_pressed;
	int 			mouse_old_x;
	int 			mouse_old_y;
}					t_data;

int					on_mouse_moved(int x, int y, void *data);
int					on_mouse_pressed(int key, int x, int y, void *data);
int					on_mouse_released(int key, int x, int y, void *data);
int					on_key_pressed(int key, void *data);
int					close_on_x(void *param);

int					init_data(t_data *data);
int					init_fract(t_data *data);
void				draw_fract(t_data *data);
int					get_fractal_id(char *str);

void				init_julia(t_data *data);
void				draw_julia(t_data *d);

void				draw_mondelbrot(t_data *d);

int					img_pixel_put(t_data *data, int x, int y, int col);
int					img_clear(t_data *data);

int					blend(int c1, int c2, double val);
int					clamp_int(int val, int min, int max);
double				map_from_0_to_1(double val, double from_min, double from_max);

int					cs_black_white(double val);
int					cs_r_g_b(double val);
int					cs_nice(double val);

#endif

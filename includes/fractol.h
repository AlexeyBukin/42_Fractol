/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:06:26 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/31 17:23:57 by kcharla          ###   ########.fr       */
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

# define E_KEY	    14
# define Q_KEY	    12

# define SCROLL_UP 	 4
# define SCROLL_DOWN 5

# define UP_KEY		126
# define DOWN_KEY	125
# define RIGHT_KEY	124
# define LEFT_KEY	123

# define W_KEY	13
# define A_KEY	0
# define S_KEY	1
# define D_KEY	2

# define NUM_1_KEY	18
# define NUM_2_KEY	19
# define NUM_3_KEY	20
# define NUM_4_KEY	21
# define NUM_5_KEY	23

# define MASK_RED   0x00FF0000
# define MASK_GREEN 0x0000FF00
# define MASK_BLUE  0x000000FF

# define SCALE_MIN 1
# define SCALE_MAX 40
# define SCALE_DELTA 0.1

# define COMPLEX_ARG_REAL_DELTA 0.1
# define COMPLEX_ARG_IMG_DELTA  0.1

# define ITERATIONS_DELTA 10

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_adr;
	double 			offset_x;
	double 			offset_y;
	int				max_iters;
	double			scale;
	double 			c_r;
	double 			c_i;
}					t_data;

int		wasd_pressed(int key, t_data *d, t_data *ref);
int		eq_pressed(int key, t_data *d, t_data *ref);
int		mouse_scrolled(int key, t_data *d, t_data *ref);

void			draw_julia(t_data *d);
void			draw_mondelbrot(t_data *d);

int					img_pixel_put(t_data *data, int x, int y, int col);
int					img_clear(t_data *data);

int		is_data_equal(const t_data *d1, const t_data *d2);

#endif

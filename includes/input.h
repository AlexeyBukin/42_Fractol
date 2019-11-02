/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 13:54:04 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/02 13:54:04 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "fractol.h"

# define ESC_KEY 	53
# define R_KEY   	15

# define E_KEY	    14
# define Q_KEY	    12

# define SCROLL_UP 	 4
# define SCROLL_DOWN 5
# define WHEEL_CLICK 3

# define SHIFT_KEY  257
# define CTRL_KEY   256

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

int		arrows_pressed(int key, t_data *d);
int		wasd_pressed(int key, t_data *d);
int		eq_pressed(int key, t_data *d);
int		shift_ctrl_pressed(int key, t_data *d);
int		num_keys_pressed(int key, t_data *d);

#endif

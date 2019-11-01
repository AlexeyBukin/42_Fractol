/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 22:02:22 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/01 21:32:54 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Function that handles arrow buttons
*/

int		arrows_pressed(int key, t_data *d, t_data *ref)
{
	if (d == NULL || ref == NULL)
		return (-1);
	if (key == RIGHT_KEY)
		d->offset_x += d->scale / 4;
	else if (key == LEFT_KEY)
		d->offset_x -= d->scale / 4;
	else if (key == UP_KEY)
		d->offset_y -= d->scale / 4;
	else if (key == DOWN_KEY)
		d->offset_y += d->scale / 4;
	else
		return (-1);
//	if (is_data_equal(d, ref))
//		return (0);
	draw_fract(d);
	return (0);
}

/*
** Function that handles WASD buttons
*/

int		wasd_pressed(int key, t_data *d, t_data *ref)
{
	if (d == NULL || ref == NULL)
		return (-1);
	if (key == D_KEY)
		d->c_i += COMPLEX_ARG_IMG_DELTA;
	else if (key == A_KEY)
		d->c_i -= COMPLEX_ARG_IMG_DELTA;
	else if (key == W_KEY)
		d->c_r += COMPLEX_ARG_REAL_DELTA;
	else if (key == S_KEY)
		d->c_r -= COMPLEX_ARG_REAL_DELTA;
	else
		return (-1);
	if (is_data_equal(d, ref))
		return (0);
	draw_fract(d);
	return (0);
}

/*
** Function that handles mouse scroll
*/



#include <stdio.h>
int		mouse_scrolled(int key, t_data *d, t_data *ref)
{
	if (d == NULL || ref == NULL)
		return (-1);
	if (key == SCROLL_UP)
		d->scale /= SCALE_DELTA;
	else if (key == SCROLL_DOWN)
		d->scale *= SCALE_DELTA;
	else
		return (-1);
	draw_fract(d);
	return (0);
}

/*
** Function that handles shift and ctrl buttons
*/

int		eq_pressed(int key, t_data *d, t_data *ref)
{
	int		max_iters_temp;

	if (d == NULL || ref == NULL)
		return (-1);
	if (key == E_KEY)
		max_iters_temp = clamp_int(d->max_iters * ITERATIONS_DELTA + 1, 2, 256);
	else if (key == Q_KEY)
		max_iters_temp = clamp_int(round (d->max_iters / ITERATIONS_DELTA - 1), 2, 256);
	else
		return (-1);
	if (max_iters_temp == d->max_iters)
		return (0);
	d->max_iters = max_iters_temp;
	draw_fract(d);
	return (0);
}

int		shift_ctrl_pressed(int key, t_data *d, t_data *ref)
{
	int		radius_temp;

	if (d == NULL || ref == NULL)
		return (-1);
	if (key == SHIFT_KEY)
		radius_temp = clamp_int(d->radius * 2, 4, 512);
	else if (key == CTRL_KEY)
		radius_temp = clamp_int(d->radius / 2, 4, 512);
	else
		return (-1);
	if (radius_temp == d->radius)
		return (0);
	d->radius = radius_temp;
	draw_fract(d);
	return (0);
}

/*
** Function that handles 1 to 3 keys
*/

int		num_keys_pressed(int key, t_data *d, t_data *ref)
{
	int 	cs_temp;

	if (d == NULL || ref == NULL)
		return (-1);
	if (key == NUM_1_KEY)
		cs_temp = COLOR_SCHEME_BW;
	else if (key == NUM_2_KEY)
		cs_temp = COLOR_SCHEME_RGB;
	else if (key == NUM_3_KEY)
		cs_temp = COLOR_SCHEME_NICE;
	else
		return (-1);
	if (cs_temp == d->color_scheme)
		return (0);
	d->color_scheme = cs_temp;
	draw_fract(d);
	return (0);
}

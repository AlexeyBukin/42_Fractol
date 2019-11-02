/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyboard_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 12:12:53 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/02 12:13:15 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

/*
** Function that handles keyboard input
*/

int		on_key_pressed(int key, void *data)
{
	t_data	*d;

	if (data == NULL)
		return (-1);
	d = (t_data *)data;
	if (arrows_pressed(key, data) >= 0)
		return (0);
	if (wasd_pressed(key, data) >= 0)
		return (0);
	if (eq_pressed(key, data) >= 0)
		return (0);
	if (shift_ctrl_pressed(key, data) >= 0)
		return (0);
	if (num_keys_pressed(key, data) >= 0)
		return (0);
	if (key == R_KEY)
		draw_fract(d);
	if (key == ESC_KEY)
		exit(0);
	return (0);
}

/*
** Function that handles shift and ctrl buttons
*/

int		eq_pressed(int key, t_data *d)
{
	int		max_iters_temp;

	if (d == NULL)
		return (-1);
	if (key == E_KEY)
		max_iters_temp = clamp_int(d->max_iters * ITERATIONS_DELTA + 1, 2, 256);
	else if (key == Q_KEY)
		max_iters_temp = clamp_int((int)round(d->max_iters / ITERATIONS_DELTA - 1), 2, 256);
	else
		return (-1);
	if (max_iters_temp == d->max_iters)
		return (0);
	d->max_iters = max_iters_temp;
	draw_fract(d);
	return (0);
}

int		shift_ctrl_pressed(int key, t_data *d)
{
	int		radius_temp;

	if (d == NULL)
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

int		num_keys_pressed(int key, t_data *d)
{
	int 	cs_temp;

	if (d == NULL)
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

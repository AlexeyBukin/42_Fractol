/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 11:49:36 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/02 13:10:06 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

/*
** Function that handles mouse scroll
*/

int		on_mouse_pressed(int key, int x, int y, void *data)
{
	t_data	*d;

	if (data == NULL)
		return (-1);
	d = (t_data *)data;
	if (key == SCROLL_UP)
		d->scale /= SCALE_DELTA;
	else if (key == SCROLL_DOWN)
		d->scale *= SCALE_DELTA;
	else if (key == WHEEL_CLICK && d->wheel_pressed == 0)
	{
		d->wheel_pressed = 1;
		d->mouse_old_x = x;
		d->mouse_old_y = y;
		return (0);
	}
	else
		return (-1);
	draw_fract(d);
	return (0);
}

int		on_mouse_released(int key, int x, int y, void *data)
{
	t_data	*d;

	(void)x;
	(void)y;
	if (data == NULL)
		return (-1);
	d = (t_data *)data;
	if (key == WHEEL_CLICK)
		d->wheel_pressed = 0;
	else
		return (-1);
	return (0);
}

int		on_mouse_moved(int x, int y, void *data)
{
	int		arg_x;
	int		arg_y;
	t_data	*d;

	if (data == NULL)
		return (-1);
	d = (t_data *)data;
	arg_x = x - d->mouse_old_x;
	arg_y = y - d->mouse_old_y;
	d->mouse_old_x = x;
	d->mouse_old_y = y;
	if (d->wheel_pressed == 1)
	{
		d->c_r += COMPLEX_ARG_REAL_DELTA * arg_x * d->scale / 100.0;
		d->c_i += COMPLEX_ARG_IMG_DELTA * arg_y * d->scale / 100.0;
		draw_fract(d);
	}
	return (0);
}

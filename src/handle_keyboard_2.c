/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 11:53:44 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/02 12:14:01 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

/*
** Function that handles arrow buttons
*/

int		arrows_pressed(int key, t_data *d)
{
	if (d == NULL)
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
	draw_fract(d);
	return (0);
}

/*
** Function that handles WASD buttons
*/

int		wasd_pressed(int key, t_data *d)
{
	if (d == NULL)
		return (-1);
	if (key == D_KEY)
		d->c_i += COMPLEX_ARG_IMG_DELTA * d->scale;
	else if (key == A_KEY)
		d->c_i -= COMPLEX_ARG_IMG_DELTA * d->scale;
	else if (key == W_KEY)
		d->c_r += COMPLEX_ARG_REAL_DELTA * d->scale;
	else if (key == S_KEY)
		d->c_r -= COMPLEX_ARG_REAL_DELTA * d->scale;
	else
		return (-1);
	draw_fract(d);
	return (0);
}

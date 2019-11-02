/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_plex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 23:55:29 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/02 23:55:36 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_plex(t_data *data)
{
	data->scale = 0.078080;
	data->color_scheme = COLOR_SCHEME_RGB;
	data->c_i = -1.035776;
	data->c_r = 0.368226;
	data->max_iters = 256;
	data->radius = 256;
	data->offset_x = -0.050730;
	data->offset_y = -0.366616;
}

int			get_iter_plex(t_data *d, int px, int py)
{
	int		iter;
	double	temp_y;
	double	temp_x;
	double	x;
	double	y;

	x = (((double)px) / 256.0 - 2.0) * d->scale + d->offset_x;
	y = (((double)py) / 256.0 - 2.0) * d->scale + d->offset_y;
	iter = 0;
	while ((x * x + y * y < d->radius) && (iter < d->max_iters))
	{
		temp_y = 4 * (x * x * x * y - x * y * y * y) + d->c_i;
		temp_x = x * x * x * x - y * y * y * y + 6 * x * x * y * y + d->c_r;
		y = temp_y;
		x = temp_x;
		iter++;
	}
	return (iter);
}

int			get_plex_color(t_data *d, int x, int y)
{
	int			final_iter;

	final_iter = get_iter_plex(d, x, y);
	if (final_iter == d->max_iters)
		return (0);
	if (d->color_scheme == COLOR_SCHEME_BW)
		return (cs_black_white(sqrt((double)final_iter / 256.0)));
	else if (d->color_scheme == COLOR_SCHEME_RGB)
		return (cs_r_g_b(sqrt((double)final_iter / 256.0)));
	else if (d->color_scheme == COLOR_SCHEME_NICE)
		return (cs_nice(sqrt((double)final_iter / 256.0)));
	return (0);
}

void		draw_plex(t_data *d)
{
	int				color;
	int				y;
	int				x;

	img_clear(d);
	y = 0;
	while (y < FRACT_BOUND_Y)
	{
		x = 0;
		while (x < FRACT_BOUND_X)
		{
			color = get_plex_color(d, x, y);
			img_pixel_put(d, x, y, color);
			x++;
		}
		y++;
	}
	mlx_clear_window(d->mlx, d->win);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}

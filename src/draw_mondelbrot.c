/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mondelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 01:10:35 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/31 17:29:50 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cx = 0.279
// cy = 0
// R = 2

#define R 4
#include <stdio.h>
#include "fractol.h"

int 			normal_mond(t_data *d, double px, double py)
{
	double x = (px / 512 - 1) * d->scale;
	double y = (py / 512 - 1) * d->scale;

	//double x = 0;
	//double y = 0;

	int iter = 0;

	while ((x * x + y*y <= 2*2) && (iter < d->max_iters))
	{
		double xold = x;
		double yold = y;
		y = 2 * x * y - d->c_i;
		x = xold * xold + yold * yold - d->c_r;
		iter++;
	}
	if (iter == ITERATION_MAX)
		return (0);
	return (iter);
}

int				get_mond_color(t_data *d, int x, int y)
{
	int			mond_res;
	int			color;

	mond_res = normal_mond(d, x, y);
//	if (mond_res > 1)
//		printf("col :%d\n", mond_res);
	color = mond_res * 256 / 10;
	return (color);
}

void			draw_mondelbrot(t_data *d)
{
	int 			color;
	int				y;
	int				x;

	img_clear(d);
	printf("x: %f, y: %f, c_r: %f, c_i: %f, scale: %f, iters: %d\n", d->offset_x, d->offset_y, d->c_r, d->c_i, d->scale, d->max_iters);
	y = 0;
	while (y < FRACT_BOUND_Y)
	{
		x = 0;
		while (x < FRACT_BOUND_Y)
		{
			color = get_mond_color(d, x, y);
			img_pixel_put(d, x, y, color);
			x++;
		}
		y++;
	}
	//printf("gonna do this x3\n");
	mlx_clear_window(d->mlx, d->win);
	//printf("gonna do this x4\n");
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	//printf("gonna do this x5\n");
}

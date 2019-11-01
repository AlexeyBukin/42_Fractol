/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 08:35:37 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/01 18:01:49 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "fdf.h"
#include "fractol.h"

/*
** Function that handles red cross exit
*/

int		close_on_x(void *param)
{
	(void)param;
	exit(0);
}

/*
** Function that handles mouse scroll
*/

int		on_mouse_scrolled(int key, int x, int y, void *data)
{
	t_data	ref;
	t_data	*d;

	x = y;
	if (data == NULL)
		return (-1);
	d = (t_data *)data;
	ref = *d;
	if (key == SCROLL_UP || key == SCROLL_DOWN)
		return (mouse_scrolled(key, data, &ref));
	return (-1);
}

/*
** Function that handles ESC key exit
*/

int		on_key_pressed(int key, void *data)
{
	t_data	ref;
	t_data	*d;

	if (data == NULL)
		return (-1);
	d = (t_data *)data;
	ref = *d;
	if (arrows_pressed(key, data, &ref) >= 0)
		return (0);
	if (wasd_pressed(key, data, &ref) >= 0)
		return (0);
	if (eq_pressed(key, data, &ref) >= 0)
		return (0);
	if (shift_ctrl_pressed(key, data, &ref) >= 0)
		return (0);
	if (num_keys_pressed(key, data, &ref) >= 0)
		return (0);
//	if (key == R_KEY)
//		draw_parallel(d);
	if (key == ESC_KEY)
		exit(0);
	return (0);
}

/*
** Function that initialize data structure
*/

int		init_data(t_data *data)
{
	int		endian;
	int		size_line;
	int		bps;

	if (data == NULL)
		return (-1);
	endian = 0;
	size_line = 0;
	bps = 0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WINDOW_BOUND_X, WINDOW_BOUND_Y, "Fractol");
	data->img = mlx_new_image(data->mlx, WINDOW_BOUND_X, WINDOW_BOUND_Y);
	data->img_adr = mlx_get_data_addr(data->img, &bps, &size_line, &endian);
	if (data->mlx == NULL || data->win == NULL)
		return (-1);
	if (data->img == NULL || data->img_adr == NULL)
		return (-2);

	if (data->fractal_id == FRACTAL_JULIA)
		init_julia(data);
//	else if (data->fractal_id == FRACTAL_MONDELBROT)
//		init_mandelbrot(data);
	else
		return (-3);

	//init_julia(data);
	return (0);
}

void	draw_fract(t_data *data)
{
	if (data->fractal_id == FRACTAL_JULIA)
		draw_julia(data);
	else if (data->fractal_id == FRACTAL_MONDELBROT)
		draw_julia(data);
}

int		get_fractal_id(char *str)
{
	if (ft_strcmp(str, "julia") == 0)
	{
		return (FRACTAL_JULIA);
	}
	else if (ft_strcmp(str, "mandelbrot") == 0)
	{
		return (FRACTAL_MONDELBROT);
	}
	else
		return (0);
}

/*
** Main function
*/

int		main(int argc, char **argv)
{
	t_data		data;

	if (argc != 2 || (data.fractal_id = get_fractal_id(argv[(argc == 2 ? 1 : 0)])) == 0)
	{
		ft_putstr("please, enter one fractal name from the list:\n 1) julia\n 2) mandelbrot\n");
		return (0);
	}
	if (init_data(&data) < 0)
	{
		ft_putstr("failed to init, exit...\n");
		return (-1);
	}
	draw_fract(&data);
	mlx_hook(data.win, 2, 0, on_key_pressed, (void *)&data);
	mlx_hook(data.win, 17, 0, close_on_x, (void *)&data);
	mlx_hook(data.win, 4, 0, on_mouse_scrolled, (void *)&data);
	mlx_loop(data.mlx);
	return (0);
}

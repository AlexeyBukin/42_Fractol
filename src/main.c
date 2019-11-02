/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 08:35:37 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/02 23:53:39 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Main function
*/

int		main(int argc, char **argv)
{
	int			error_code;
	t_data		data;

	data.fractal_id = get_fractal_id(argv[(argc == 2 ? 1 : 0)]);
	if (argc != 2 || data.fractal_id == 0)
	{
		ft_putstr("please, enter one fractal name "
			"from the list:\n 1) julia\n 2) mandelbrot\n 3) plex\n");
		return (0);
	}
	if ((error_code = init_data(&data)) < 0)
	{
		ft_putstr("failed to init, exit...\n[ error code is: ");
		ft_putstr(ft_itoa(error_code));
		ft_putstr(" ]\n");
		return (-1);
	}
	draw_fract(&data);
	mlx_hook(data.win, 2, 0, on_key_pressed, (void *)&data);
	mlx_hook(data.win, 17, 0, close_on_x, (void *)&data);
	mlx_hook(data.win, 4, 0, on_mouse_pressed, (void *)&data);
	mlx_hook(data.win, 6, 0, on_mouse_moved, (void *)&data);
	mlx_hook(data.win, 5, 0, on_mouse_released, (void *)&data);
	mlx_loop(data.mlx);
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
	data->wheel_pressed = 0;
	data->mouse_old_x = 0;
	data->mouse_old_y = 0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx,
			WINDOW_BOUND_X, WINDOW_BOUND_Y, "Fractol");
	data->img = mlx_new_image(data->mlx, WINDOW_BOUND_X, WINDOW_BOUND_Y);
	data->img_adr = mlx_get_data_addr(data->img, &bps, &size_line, &endian);
	if (data->mlx == NULL || data->win == NULL)
		return (-2);
	if (data->img == NULL || data->img_adr == NULL)
		return (-3);
	if (init_fract(data) < 0)
		return (-4);
	return (0);
}

int		init_fract(t_data *data)
{
	if (data == NULL)
		return (-1);
	if (data->fractal_id == FRACTAL_JULIA)
		init_julia(data);
	else if (data->fractal_id == FRACTAL_MANDELBROT)
		init_mandelbrot(data);
	else if (data->fractal_id == FRACTAL_PLEX)
		init_plex(data);
	else
		return (-2);
	return (0);
}

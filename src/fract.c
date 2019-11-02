/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 11:37:18 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/02 22:22:04 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Main function
*/

void	draw_fract(t_data *data)
{
	if (data->fractal_id == FRACTAL_JULIA)
		draw_julia(data);
	else if (data->fractal_id == FRACTAL_MANDELBROT)
		draw_mandelbrot(data);
	else if (data->fractal_id == FRACTAL_PLEX)
		draw_plex(data);
}

/*
** Sets fractal ID by argument string
*/

int		get_fractal_id(char *str)
{
	if (ft_strcmp(str, "julia") == 0)
	{
		return (FRACTAL_JULIA);
	}
	else if (ft_strcmp(str, "mandelbrot") == 0)
	{
		return (FRACTAL_MANDELBROT);
	}
	else if (ft_strcmp(str, "plex") == 0)
	{
		return (FRACTAL_PLEX);
	}
	else
		return (0);
}

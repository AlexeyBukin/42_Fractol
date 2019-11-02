/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 11:37:18 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/02 11:37:18 by kcharla          ###   ########.fr       */
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
    else if (data->fractal_id == FRACTAL_MONDELBROT)
        draw_julia(data);
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
        return (FRACTAL_MONDELBROT);
    }
    else
        return (0);
}
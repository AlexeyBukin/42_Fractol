/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 05:39:53 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/02 13:17:45 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Function blends two colors by the given value
*/

int			blend(int c1, int c2, double val)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = (c2 & MASK_RED) >> 16;
	r = t + (((c1 & MASK_RED) >> 16) - t) * val;
	t = (c2 & MASK_GREEN) >> 8;
	g = t + (((c1 & MASK_GREEN) >> 8) - t) * val;
	t = (c2 & MASK_BLUE);
	b = t + ((c1 & MASK_BLUE) - t) * val;
	t = ((int)(r << 16)) + ((int)(g << 8)) + b;
	return (t);
}

/*
** Function that clamps value from min to max
*/

double		clamp(double val, double min, double max)
{
	if (val < min)
	{
		return (min);
	}
	if (val > max)
	{
		return (max);
	}
	return (val);
}

/*
** Function that clamps value from min to max
*/

int			clamp_int(int val, int min, int max)
{
	if (val < min)
	{
		return (min);
	}
	if (val > max)
	{
		return (max);
	}
	return (val);
}

/*
** Function that loops value within min and max
*/

double		cycle(double val, double min, double max)
{
	while (val > max)
	{
		val = min + (val - max);
	}
	while (val < min)
	{
		val = max - (min - val);
	}
	return (val);
}

/*
** Function that maps value from one range to another
*/

double		map_from_0_to_1(double val, double from_min, double from_max)
{
	val = (val - from_min) / (from_max - from_min);
	return (val);
}

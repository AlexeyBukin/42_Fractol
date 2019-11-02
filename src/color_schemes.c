/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 05:39:53 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/02 13:23:27 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Simple black-white color scheme
*/

int		cs_black_white(double val)
{
	int	t;

	t = round(val * 255.0);
	t = ((int)(t << 16)) + ((int)(t << 8)) + t;
	return (t);
}

/*
** Simple red to green to blue color scheme
*/

int		cs_r_g_b(double val)
{
	if (val < 0.5)
	{
		return (blend(0x00008800, 0x00AA0000, val * 2));
	}
	return (blend(0x000000AA, 0x0000AA00, (val - 0.5) * 2));
}

/*
** Simple red to green to blue color scheme
*/

int		cs_nice(double val)
{
	if (val < 0.125)
		return (blend(0x0000AAAA, 0x00000000, map_from_0_to_1(val, 0, 0.125)));
	if (val < 0.25)
		return (blend(0xAA, 0x0000AAAA, map_from_0_to_1(val, 0.125, 0.25)));
	if (val < 0.5)
		return (blend(0x00AA00AA, 0x000000AA, map_from_0_to_1(val, 0.25, 0.5)));
	return (blend(0x0000AA00, 0x00AA00AA, map_from_0_to_1(val, 0.5, 1)));
}

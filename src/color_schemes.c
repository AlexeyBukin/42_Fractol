/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 05:39:53 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/01 21:07:22 by kcharla          ###   ########.fr       */
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
		return (blend(0x0000AAAA, 0x00000000, map(val, 0, 0.125, 0, 1)));
	if (val < 0.25)
		return (blend(0x000000AA, 0x0000AAAA, map(val, 0.125, 0.25, 0, 1)));
	if (val < 0.5)
		return (blend(0x00AA00AA, 0x000000AA, map(val, 0.25, 0.5, 0, 1)));
	return (blend(0x0000AA00, 0x00AA00AA, map(val, 0.5, 1, 0, 1)));
}

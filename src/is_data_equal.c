/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_data_equal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 22:24:11 by kcharla           #+#    #+#             */
/*   Updated: 2019/10/31 16:14:28 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Function that compares two t_data structs
*/

int		is_data_equal(const t_data *d1, const t_data *d2)
{
	int		res;

	if (d1 == 0 || d2 == 0)
	{
		if (d1 == 0 && d2 == 0)
			return (1);
		return (0);
	}
	res = (d1->c_i == d2->c_i);
	res = res && (d1->c_r == d2->c_r);
	res = res && (d1->scale == d2->scale);
	res = res && (d1->max_iters == d2->max_iters);
	return (res);
}

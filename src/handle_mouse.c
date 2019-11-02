/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 11:49:36 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/02 11:55:46 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

/*
** Function that handles mouse scroll
*/

int		on_mouse_pressed(int key, int x, int y, void *data)
{
    t_data	*d;

    (void)x;
    (void)y;
    if (data == NULL)
        return (-1);
    d = (t_data *)data;
    if (key == SCROLL_UP)
        d->scale /= SCALE_DELTA;
    else if (key == SCROLL_DOWN)
        d->scale *= SCALE_DELTA;
    else
        return (-1);
    draw_fract(d);
    return (0);
}

int     on_mouse_moved(int x, int y, void *data)
{
    (void)x;
    (void)y;
    (void)data;
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 11:49:28 by kcharla           #+#    #+#             */
/*   Updated: 2019/11/02 11:49:28 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

/*
** Function that handles red cross exit
*/

int		close_on_x(void *param)
{
	(void)param;
	exit(0);
}

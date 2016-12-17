/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_move_camera.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 20:19:56 by cledant           #+#    #+#             */
/*   Updated: 2016/01/21 20:35:49 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	fractol_move_camera(t_env *e, size_t type)
{
	if (type == 0)
	{
		e->height_min = e->height_min + 50 * e->height_pitch;
		e->height_max = e->height_max + 50 * e->height_pitch;
	}
	else if (type == 1)
	{
		e->height_min = e->height_min - 50 * e->height_pitch;
		e->height_max = e->height_max - 50 * e->height_pitch;
	}
	else if (type == 2)
	{
		e->width_min = e->width_min + 50 * e->width_pitch;
		e->width_max = e->width_max + 50 * e->width_pitch;
	}
	else if (type == 3)
	{
		e->width_min = e->width_min - 50 * e->width_pitch;
		e->width_max = e->width_max - 50 * e->width_pitch;
	}
	e->render = 1;
}

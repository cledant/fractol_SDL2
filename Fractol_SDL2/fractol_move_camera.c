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

void	fractol_move_camera(t_var *v, char type)
{
	if (type == 0)
	{
		v->height_min = v->height_min + 50 * v->height_pitch;
		v->height_max = v->height_max + 50 * v->height_pitch;
	}
	else if (type == 1)
	{
		v->height_min = v->height_min - 50 * v->height_pitch;
		v->height_max = v->height_max - 50 * v->height_pitch;
	}
	else if (type == 2)
	{
		v->width_min = v->width_min + 50 * v->width_pitch;
		v->width_max = v->width_max + 50 * v->width_pitch;
	}
	else if (type == 3)
	{
		v->width_min = v->width_min - 50 * v->width_pitch;
		v->width_max = v->width_max - 50 * v->width_pitch;
	}
	v->render = 1;
}

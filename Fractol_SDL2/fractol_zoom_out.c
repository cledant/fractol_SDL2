/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_zoom_out.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 11:14:58 by cledant           #+#    #+#             */
/*   Updated: 2016/01/23 20:43:01 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void			fractol_zoom_out(t_var *v)
{
	if (v->zoom != 1)
	{
		v->offset_width = v->m_width - (v->win_width / 2);
		v->offset_height = v->m_height - (v->win_height / 2);
		v->width_min = v->width_min + (v->width_pitch * v->offset_width);
		v->width_max = v->width_max + (v->width_pitch * v->offset_width);
		v->height_min = v->height_min + (v->height_pitch * -v->offset_height);
		v->height_max = v->height_max + (v->height_pitch * -v->offset_height);
		v->width_min = v->width_min - (4 / (v->zoom + v->zoom));
		v->width_max = v->width_max + (4 / (v->zoom + v->zoom));
		v->height_min = v->height_min - (4 / (v->zoom + v->zoom));
		v->height_max = v->height_max + (4 / (v->zoom + v->zoom));
		v->zoom = v->zoom / 2;
		v->width_pitch = fractol_pitch_value(v->width_min, v->width_max, v->win_width);
		v->height_pitch = fractol_pitch_value(v->height_min, v->height_max, v->win_height);
		v->width_min = v->width_min - (v->offset_width * v->width_pitch);
		v->width_max = v->width_max - (v->offset_width * v->width_pitch);
		v->height_min = v->height_min - (-v->offset_height * v->height_pitch);
		v->height_max = v->height_max - (-v->offset_height * v->height_pitch);
		v->render = 1;
	}
}

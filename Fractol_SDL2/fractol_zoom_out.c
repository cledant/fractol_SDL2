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

void			fractol_zoom_out(t_env *e)
{
	if (e->zoom != 1)
	{
		e->offset_width = fractol_seek_offset(e->win_width, e->m_width);
		e->offset_height = fractol_seek_offset(e->win_height, e->m_height);
		e->width_min = fractol_offset_value(e->width_min, e->offset_width, e->width_pitch);
		e->width_max = fractol_offset_value(e->width_max, e->offset_width, e->width_pitch);
		e->height_min = fractol_offset_value(e->height_min, -e->offset_height, e->height_pitch);
		e->height_max = fractol_offset_value(e->height_max, -e->offset_height, e->height_pitch);
		e->width_min = e->width_min - (4 / (e->zoom + e->zoom));
		e->width_max = e->width_max + (4 / (e->zoom + e->zoom));
		e->height_min = e->height_min - (4 / (e->zoom + e->zoom));
		e->height_max = e->height_max + (4 / (e->zoom + e->zoom));
		e->zoom = e->zoom / 2;
		e->width_pitch = fractol_pitch_value(e->width_min, e->width_max, e->win_width);
		e->height_pitch = fractol_pitch_value(e->height_min, e->height_max, e->win_height);
		e->width_min = e->width_min - (e->offset_width * e->width_pitch);
		e->width_max = e->width_max - (e->offset_width * e->width_pitch);
		e->height_min = e->height_min - (-e->offset_height * e->height_pitch);
		e->height_max = e->height_max - (-e->offset_height * e->height_pitch);
		e->render = 1;
	}
}

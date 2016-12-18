/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_reset_view.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:01:36 by cledant           #+#    #+#             */
/*   Updated: 2016/01/23 10:21:29 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	fractol_reset_view(t_var *v)
{
	v->zoom = 1;
	v->m_width = v->win_width / 2;
	v->m_height = v->win_height / 2;
	v->m_width_old = v->win_width / 2;
	v->m_height_old = v->win_height / 2;
	v->width_min = -2;
	v->width_max = 2;
	v->height_min = -2;
	v->height_max = 2;
	v->color = 1;
	v->iter = 100;
	v->width_pitch = fractol_pitch_value(v->width_min, v->width_max,
		v->win_width);
	v->height_pitch = fractol_pitch_value(v->height_min, v->height_max,
		v->win_height);
	v->mouse_tracking = 1;
	v->render = 1;
}
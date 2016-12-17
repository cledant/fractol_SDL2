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

void	fractol_reset_view(t_env *e)
{
	e->zoom = 1;
	e->m_width = e->win_width / 2;
	e->m_height = e->win_height / 2;
	e->m_width_old = e->win_width / 2;
	e->m_height_old = e->win_height / 2;
	e->width_min = -2;
	e->width_max = 2;
	e->height_min = -2;
	e->height_max = 2;
	e->color = 1;
	e->iter = 100;
	e->width_pitch = fractol_pitch_value(e->width_min, e->width_max,
		e->win_width);
	e->height_pitch = fractol_pitch_value(e->height_min, e->height_max,
		e->win_height);
	e->mouse_tracking = 1;
	e->render = 1;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_set_mouse_tracking.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 10:14:00 by cledant           #+#    #+#             */
/*   Updated: 2016/01/22 10:59:02 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	fractol_set_mouse_tracking(t_var *v)
{
	if (v->mouse_tracking == 0)
		v->mouse_tracking = 1;
	else if (v->mouse_tracking == 1)
	{
		v->mouse_tracking = 0;
		v->m_width_old = v->m_width;
		v->m_height_old = v->m_height;
		v->m_width = (v->win_width) / 2;
		v->m_height = (v->win_height) / 2;
	}
}
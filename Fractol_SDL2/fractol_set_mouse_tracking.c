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

void	fractol_set_mouse_tracking(t_env *e)
{
	if (e->mouse_tracking == 0)
		e->mouse_tracking = 1;
	else if (e->mouse_tracking == 1)
	{
		e->mouse_tracking = 0;
		e->m_width_old = e->m_width;
		e->m_height_old = e->m_height;
		e->m_width = (e->win_width) / 2;
		e->m_height = (e->win_height) / 2;
	}
}
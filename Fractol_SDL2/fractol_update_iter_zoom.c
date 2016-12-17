/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_update_iter_zoom.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:42:33 by cledant           #+#    #+#             */
/*   Updated: 2016/01/24 12:16:34 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_err	fractol_update_iter_zoom(t_env *e)
{
	t_err	err = NONE;

	fractol_destroy_texture(&(e->zoom_counter));
	fractol_destroy_texture(&(e->iter_counter));
	sprintf(e->s, "%.3e", e->zoom);
	if ((err = fractol_create_texture_name(&(e->zoom_counter), e->renderer,
			e->font_m, 70, 35, e->c_white, e->s)) != NONE)
		return (err);
	sprintf(e->s, "%d", e->iter);
	if ((err = fractol_create_texture_name(&(e->iter_counter), e->renderer,
			e->font_m, 95, 60, e->c_white, e->s)) != NONE)
		return (err);
	return (NONE);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_resize_window.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:42:33 by cledant           #+#    #+#             */
/*   Updated: 2016/01/24 12:16:34 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void		recalc_pitch(t_env *e)
{
	e->width_pitch = fractol_pitch_value(e->width_min, e->width_max, e->win_width);
	e->height_pitch = fractol_pitch_value(e->height_min, e->height_max, e->win_height);
}

char			fractol_resize_window(t_env *e)
{
	char		resize = 0;

	e->win_height = e->ev.window.data2;
	e->win_width = e->ev.window.data1;
	if (e->win_height < 500)
	{
		e->win_height = 500;
		resize = 1;
	}
	if (e->win_width < 500)
	{
		e->win_width = 500;
		resize = 1;
	}
	if (e->win_height > 1080)
	{
		e->win_height = 1080;
		resize = 1;
	}
	if (e->win_width > 1920)
	{
		e->win_width = 1920;
		resize = 1;
	}
	if (resize == 1)
		SDL_SetWindowSize(e->win, e->win_width, e->win_height);
	fractol_set_rect(&(e->fractal.rect_s), 0, 0, e->win_width, e->win_height);
	fractol_set_rect(&(e->fractal.rect_d), 0, 0, e->win_width, e->win_height);
	recalc_pitch(e);
	e->render = 1;
	SDL_FreeSurface(e->fractal.surf);
	if ((e->fractal.surf = SDL_CreateRGBSurface(0, e->win_width, e->win_height,
			32, 0, 0, 0, 0)) == NULL)
		return (0);
	return (1);
}
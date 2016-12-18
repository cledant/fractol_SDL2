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

t_err			fractol_resize_window(t_var *v, SDL_Window *win, t_texture *fractal,
					const SDL_Event *ev)
{
	char		resize = 0;

	v->win_height = ev->window.data2;;
	v->win_width = ev->window.data1;
	if (v->win_height < 500)
	{
		v->win_height = 500;
		resize = 1;
	}
	if (v->win_width < 500)
	{
		v->win_width = 500;
		resize = 1;
	}
	if (v->win_height > 1080)
	{
		v->win_height = 1080;
		resize = 1;
	}
	if (v->win_width > 1920)
	{
		v->win_width = 1920;
		resize = 1;
	}
	if (resize == 1)
		SDL_SetWindowSize(win, v->win_width, v->win_height);
	fractol_set_rect(&(fractal->rect_s), 0, 0, v->win_width, v->win_height);
	fractol_set_rect(&(fractal->rect_d), 0, 0, v->win_width, v->win_height);
	v->width_pitch = fractol_pitch_value(v->width_min, v->width_max, v->win_width);
	v->height_pitch = fractol_pitch_value(v->height_min, v->height_max, v->win_height);
	v->render = 1;
	SDL_FreeSurface(fractal->surf);
	if ((fractal->surf = SDL_CreateRGBSurface(0, v->win_width, v->win_height,
			32, 0, 0, 0, 0)) == NULL)
		return (E_SURFACE);
	return (NONE);
}
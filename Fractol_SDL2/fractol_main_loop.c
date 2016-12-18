/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:42:33 by cledant           #+#    #+#             */
/*   Updated: 2016/01/24 12:16:34 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void		fractol_exit(t_env *e, char *run, t_err err)
{
	*run = 0;
	if (err == NONE)
		fractol_sdl_exit(e);
	else
		fractol_error(e, err);
}

void			fractol_main_loop(t_env *e)
{
	char	run = 1;
	t_err	err = NONE;

	while (run)
	{
		while (SDL_PollEvent(&e->ev))
		{
			if (e->ev.type == SDL_QUIT)
			{
				fractol_exit(e, &run, NONE);
				break;
			}
			else if (e->ev.type == SDL_WINDOWEVENT)
			{
				if (e->ev.window.event == SDL_WINDOWEVENT_RESIZED)
					if ((err = fractol_resize_window(&(e->var), e->win,
						&(e->fractal), &(e->ev))) != NONE)
					{
						fractol_exit(e, &run, err);
						break;
					}
			}
			else if (e->ev.type == SDL_KEYDOWN)
			{
				if (e->ev.key.keysym.sym == SDLK_ESCAPE)
				{
					fractol_exit(e, &run, NONE);
					break;
				}
				else if (e->ev.key.keysym.sym == SDLK_r)
					fractol_reset_view(&(e->var));
				else if (e->ev.key.keysym.sym == SDLK_c)
					fractol_change_color(&(e->var));
				else if (e->ev.key.keysym.sym == SDLK_TAB)
					fractol_change_fractal(&(e->var));
				else if (e->ev.key.keysym.sym == SDLK_KP_PLUS)
					fractol_zoom_in(&(e->var));
				else if (e->ev.key.keysym.sym == SDLK_KP_MINUS)
					fractol_zoom_out(&(e->var));
				else if (e->ev.key.keysym.sym == SDLK_i)
					fractol_change_iter(&(e->var), 1);
				else if (e->ev.key.keysym.sym == SDLK_u)
					fractol_change_iter(&(e->var), 0);
				else if (e->ev.key.keysym.sym == SDLK_UP)
					fractol_move_camera(&(e->var), 0);
				else if (e->ev.key.keysym.sym == SDLK_DOWN)
					fractol_move_camera(&(e->var), 1);
				else if (e->ev.key.keysym.sym == SDLK_RIGHT)
					fractol_move_camera(&(e->var), 2);
				else if (e->ev.key.keysym.sym == SDLK_LEFT)
					fractol_move_camera(&(e->var), 3);
				else if (e->ev.key.keysym.sym == SDLK_m)
					fractol_set_mouse_tracking(&(e->var));
			}
			else if (e->ev.type == SDL_MOUSEMOTION && e->var.mouse_tracking == 1)
				fractol_mouse_position(&(e->var));
			else if (e->ev.type == SDL_MOUSEWHEEL)
			{
				if (e->ev.wheel.y < 0)
					fractol_zoom_out(&(e->var));
				else
					fractol_zoom_in(&(e->var));
			}
			if (e->var.render == 1)
				if ((err = fractol_draw_fractal(e)) != NONE)
				{
					fractol_exit(e, &run, err);
					break;
				}
		}
	}
}
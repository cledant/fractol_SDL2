/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:42:33 by cledant           #+#    #+#             */
/*   Updated: 2016/01/24 12:16:34 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void		init_pointer(t_env *e)
{
	e->win = NULL;
	e->renderer = NULL;
	e->font_m = NULL;
}

static t_err		init_env(t_env *e)
{
	e->win_width = 500;
	e->win_height = 500;
	e->fractal_nb = 0;
	fractol_reset_view(e);
	if ((e->win = SDL_CreateWindow("Fractol", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, e->win_width, e->win_height,
			SDL_WINDOW_RESIZABLE)) == NULL)
		return (E_WINDOW);
	if ((e->renderer = SDL_CreateRenderer(e->win, -1, SDL_RENDERER_ACCELERATED))
			== NULL)
		return (E_RENDERER);
	fractol_set_rect(&(e->fractal.rect_s), 0, 0, e->win_width, e->win_height);
	fractol_set_rect(&(e->fractal.rect_d), 0, 0, e->win_width, e->win_height);
	if ((e->fractal.surf = SDL_CreateRGBSurface(0, e->win_width, e->win_height,
			32, 0, 0, 0, 0)) == NULL)
		return (E_SURFACE);
	return (NONE);
}

static t_err		init_font(t_env *e)
{
	if ((e->font_m = TTF_OpenFont(FONT, 24)) == NULL)
		return (E_TTF_OPEN);
	fractol_set_sdl_color(&(e->c_white), 255, 255, 255, 255);
	fractol_set_sdl_color(&(e->c_black), 0, 0, 0, 255);
	fractol_set_sdl_color(&(e->c_transparent), 0, 0, 0, 0);
	return (NONE);
}

static t_err		init_name_tex(t_env *e)
{
	t_err	err = NONE;

	if ((err = fractol_create_texture_name(&(e->mandel_name), e->renderer,
			e->font_m, 10, 10, e->c_white, "Fractal : Mandelbrot")) != NONE)
		return (err);
	if ((err = fractol_create_texture_name(&(e->julia_name), e->renderer,
			e->font_m, 10, 10, e->c_white, "Fractal : Julia")) != NONE)
		return (err);
	if ((err = fractol_create_texture_name(&(e->bs_name), e->renderer,
			e->font_m, 10, 10, e->c_white, "Fractal : Burningship")) != NONE)
		return (err);
	if ((err = fractol_create_texture_name(&(e->julia_bs_name), e->renderer,
			e->font_m, 10, 10, e->c_white, "Fractal : Julia_Burningship")) != NONE)
		return (err);
	if ((err = fractol_create_texture_name(&(e->zoom_name), e->renderer,
			e->font_m, 10, 35, e->c_white, "Zoom :")) != NONE)
		return (err);
	if ((err = fractol_create_texture_name(&(e->iter_name), e->renderer,
			e->font_m, 10, 60, e->c_white, "Iteration :")) != NONE)
		return (err);
	return (NONE);
}

static void			init_tex(t_env *e)
{
	fractol_init_texture(&(e->fractal));
	fractol_init_texture(&(e->mandel_name));
	fractol_init_texture(&(e->bs_name));
	fractol_init_texture(&(e->julia_name));
	fractol_init_texture(&(e->julia_bs_name));
	fractol_init_texture(&(e->zoom_name));
	fractol_init_texture(&(e->zoom_counter));
	fractol_init_texture(&(e->iter_name));
	fractol_init_texture(&(e->iter_counter));
}

int				main(void)
{
	t_env		e;
	t_err		err = NONE;

	init_pointer(&e);
	init_tex(&e);
	if (TTF_Init() != 0)
	{
		fractol_error(&e, E_TTF_INIT);
		return (0);
	}
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fractol_error(&e, E_INIT);
		return (0);
	}
	if ((err = init_font(&e)) != NONE)
	{
		fractol_error(&e, err);
		return (0);
	}
	if ((err = init_env(&e)) != NONE)
	{
		fractol_error(&e, err);
		return (0);
	}
	if ((err = init_name_tex(&e)) != NONE)
	{
		fractol_error(&e, err);
		return (0);
	}
	fractol_main_loop(&e);
	return (1);
}

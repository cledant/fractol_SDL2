/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_create_renderer_image.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:42:33 by cledant           #+#    #+#             */
/*   Updated: 2016/01/24 12:16:34 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static t_err	name_copy(t_env *e)
{
	t_err	err = NONE;

	if (e->var.fractal_nb == MANDELBROT)
	{
		if (SDL_RenderCopy(e->renderer, e->mandel_name.tex, &(e->mandel_name.rect_s),
				&(e->mandel_name.rect_d)) == -1)
			return (E_COPY_RENDERER);
	}
	else if (e->var.fractal_nb == JULIA)
	{
		if (SDL_RenderCopy(e->renderer, e->julia_name.tex, &(e->julia_name.rect_s),
				&(e->julia_name.rect_d)) == -1)
			return (E_COPY_RENDERER);
	}
	else if (e->var.fractal_nb == BURNING_SHIP)
	{
		if (SDL_RenderCopy(e->renderer, e->bs_name.tex, &(e->bs_name.rect_s),
				&(e->bs_name.rect_d)) == -1)
			return (E_COPY_RENDERER);
	}
	else if (e->var.fractal_nb == JULIA_BURNING_SHIP)
	{
		if (SDL_RenderCopy(e->renderer, e->julia_bs_name.tex, &(e->julia_bs_name.rect_s),
				&(e->julia_bs_name.rect_d)) == -1)
			return (E_COPY_RENDERER);
	}
	return (NONE);
}

t_err		fractol_create_renderer_image(t_env *e)
{
	t_err	err = NONE;

	if (SDL_RenderCopy(e->renderer, e->fractal.tex, &(e->fractal.rect_s),
			&(e->fractal.rect_d)) == -1)
		return (E_COPY_RENDERER);
	if ((err = name_copy(e)) != NONE)
		return (err);
	if (SDL_RenderCopy(e->renderer, e->iter_name.tex, &(e->iter_name.rect_s),
			&(e->iter_name.rect_d)) == -1)
		return (E_COPY_RENDERER);
	if (SDL_RenderCopy(e->renderer, e->iter_counter.tex, &(e->iter_counter.rect_s),
		&(e->iter_counter.rect_d)) == -1)
		return (E_COPY_RENDERER);
	if (SDL_RenderCopy(e->renderer, e->zoom_name.tex, &(e->zoom_name.rect_s),
			&(e->zoom_name.rect_d)) == -1)
		return (E_COPY_RENDERER);
	if (SDL_RenderCopy(e->renderer, e->zoom_counter.tex, &(e->zoom_counter.rect_s),
		&(e->zoom_counter.rect_d)) == -1)
		return (E_COPY_RENDERER);
	return (NONE);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw_fractal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:42:33 by cledant           #+#    #+#             */
/*   Updated: 2016/01/24 12:16:34 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_err	fractol_draw_fractal(t_env *e)
{
	t_err	err = NONE;

	memset(e->fractal.surf->pixels, 0, 4 * e->var.win_width * e->var.win_height);
	if (e->var.fractal_nb == MANDELBROT)
		fractol_mandelbrot(e);
	else if (e->var.fractal_nb == JULIA)
		fractol_julia(e);
	else if (e->var.fractal_nb == BURNING_SHIP)
		fractol_burningship(e);
	else if (e->var.fractal_nb == JULIA_BURNING_SHIP)
		fractol_julia_burningship(e);
	if (e->fractal.tex != NULL)
		SDL_DestroyTexture(e->fractal.tex);
	if ((e->fractal.tex = SDL_CreateTextureFromSurface(e->renderer, e->fractal.surf))
			== NULL)
		return (E_TEXTURE);
	if ((err = fractol_update_iter_zoom(e)) != NONE)
		return (err);
	if ((err = fractol_create_renderer_image(e)) != NONE)
		return (err);
	SDL_RenderPresent(e->renderer);
	e->var.render = 0;
	return (NONE);
}
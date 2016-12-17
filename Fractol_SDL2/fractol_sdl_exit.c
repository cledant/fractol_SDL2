/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_sdl_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:42:33 by cledant           #+#    #+#             */
/*   Updated: 2016/01/24 12:16:34 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void		fractol_sdl_exit(t_env *e)
{
	fractol_destroy_texture(&(e->fractal));
	fractol_destroy_texture(&(e->mandel_name));
	fractol_destroy_texture(&(e->julia_name));
	fractol_destroy_texture(&(e->bs_name));
	fractol_destroy_texture(&(e->julia_bs_name));
	fractol_destroy_texture(&(e->iter_name));
	fractol_destroy_texture(&(e->iter_counter));
	fractol_destroy_texture(&(e->zoom_name));
	fractol_destroy_texture(&(e->zoom_counter));
	if (e->renderer!= NULL)
		SDL_DestroyRenderer(e->renderer);
	if (e->win != NULL)
		SDL_DestroyWindow(e->win);
	if (e->font_m != NULL)
		TTF_CloseFont(e->font_m);
	SDL_Quit();
	TTF_Quit();
}
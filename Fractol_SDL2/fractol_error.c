/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:42:33 by cledant           #+#    #+#             */
/*   Updated: 2016/01/24 12:16:34 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	fractol_error(t_env *e, const t_err err)
{
	if (err == E_SURFACE)
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error",
			"Can't create surface", NULL);
	else if (err == E_RENDERER)
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error",
			"Can't create renderer", NULL);
	else if (err == E_WINDOW)
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error",
			"Can't create window", NULL);
	else if (err == E_INIT)
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error",
			"Can't initialize SDL", NULL);
	else if (err == E_TEXTURE)
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error",
			"Can't create texture", NULL);
	else if (err == E_COPY_RENDERER)
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error",
			"Can't copy to renderer", NULL);
	else if (err == E_CLEAR_RENDERER)
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error",
			"Can't clear renderer", NULL);
	else if (err == E_TTF_INIT)
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error",
			"Can't init text renderer", NULL);
	else if (err == E_TTF_OPEN)
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error",
			"Can't open font", NULL);
	else if (err == E_TTF_SIZE)
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error",
			"Can't find surface font size", NULL);
	else if (err == E_TTF_SURF)
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error",
			"Can't create surface from text", NULL);
	fractol_sdl_exit(e);
}
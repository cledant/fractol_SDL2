/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_display_name.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:01:36 by cledant           #+#    #+#             */
/*   Updated: 2016/01/23 10:21:29 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_err	fractol_create_texture_name(t_texture *t, SDL_Renderer *renderer,
			TTF_Font *font, const int pos_width, const int pos_height,
			const SDL_Color color, const char *s)
{
	if ((t->surf = TTF_RenderText_Blended(font, s, color)) == NULL)
		return (E_TTF_SURF);
	if ((t->tex = SDL_CreateTextureFromSurface(renderer, t->surf)) == NULL)
		return (E_TEXTURE);
	fractol_set_rect(&(t->rect_s), 0, 0, 0, 0);
	if (TTF_SizeText(font, s, &(t->rect_s.w), &(t->rect_s.h)) != 0)
		return (E_TTF_SIZE);
	fractol_set_rect(&(t->rect_d), pos_width, pos_height, t->rect_s.w, t->rect_s.h);
	return (NONE);
}
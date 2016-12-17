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

void	fractol_destroy_texture(t_texture *t)
{
	if (t->surf != NULL)
		SDL_FreeSurface(t->surf);
	if (t->tex != NULL)
		SDL_DestroyTexture(t->tex);
	fractol_set_rect(&(t->rect_s), 0, 0, 0, 0);
	fractol_set_rect(&(t->rect_d), 0, 0, 0, 0);
}
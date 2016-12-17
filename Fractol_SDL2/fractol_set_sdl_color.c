/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_set_sdl_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:01:36 by cledant           #+#    #+#             */
/*   Updated: 2016/01/23 10:21:29 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	fractol_set_sdl_color(SDL_Color *color, const unsigned char r,
			const unsigned char g, const unsigned char b,
			const unsigned char a)
{
	color->r = r;
	color->g = g;
	color->b = b;
	color->a = a;
}
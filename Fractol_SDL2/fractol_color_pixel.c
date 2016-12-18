/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color_pixel.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:27:08 by cledant           #+#    #+#             */
/*   Updated: 2016/01/23 18:16:50 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	fractol_color_pixel(t_texture *t, const char color,
			const int win_width, const int i, const int j,
			const size_t cur_it)
{
	unsigned int *img = t->surf->pixels;

	if (color == 1)
		img[win_width * j + i] = 0x000000FF + (cur_it * 0x000FF000);
	else if (color == 2)
		img[win_width * j + i] = 0x000F0F0F + (cur_it * 0x00102030);
	else if (color == 3)
		img[win_width * j + i] = 0x00F0000F + (cur_it * 0x00111111);
	else if (color == 4)
		img[win_width * j + i] = 0x00000000 + (cur_it * 0x00060006);
	else if (color == 5)
		img[win_width * j + i] = 0x00A4B580 + (cur_it * 0x00341165);
	else if (color == 6)
		img[win_width * j + i] = 0x00000000 + (cur_it * 0x00060100);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mouse_position.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:42:33 by cledant           #+#    #+#             */
/*   Updated: 2016/01/24 12:16:34 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	fractol_mouse_position(t_var *v)
{
	SDL_GetMouseState(&(v->m_width), &(v->m_height));
	if (v->fractal_nb == JULIA || v->fractal_nb == JULIA_BURNING_SHIP)
		v->render = 1;
}
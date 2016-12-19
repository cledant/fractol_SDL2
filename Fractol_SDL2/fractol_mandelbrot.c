/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandelbrot.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:35:05 by cledant           #+#    #+#             */
/*   Updated: 2016/01/22 18:48:01 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void		fractol_mandelbrot(t_env *e)
{
	int		i = 0;
	int		j = 0;
	size_t	cur_it = 0;
	double	z_r = 0;
	double	z_i = 0;
	double	res = 0;
	double	tmp_r = 0;
	double	tmp_i = 0;
	double	sqrt_tmp_x = 0;
	double	sqrt_tmp_y = 0;

	while (j < e->var.win_height)
	{
		while (i < e->var.win_width)
		{
			while (cur_it < e->var.iter)
			{
				tmp_r = z_r;
				tmp_i = z_i;
				sqrt_tmp_x = tmp_r * tmp_r;
				sqrt_tmp_y = tmp_i * tmp_i;
				z_r = (sqrt_tmp_x - sqrt_tmp_y + e->var.width_min +
					(e->var.width_pitch * i));
				z_i = tmp_r * tmp_i;
				z_i += z_i;
				z_i += (e->var.height_max - (e->var.height_pitch * j));
				if ((res = (z_r * z_r) + (z_i * z_i)) > 4)
					break ;
				cur_it++;
			}
			if (res > 4)
				fractol_color_pixel(&(e->fractal), e->var.color, e->var.win_width,
					i, j, cur_it);
			z_r = 0;
			z_i = 0;
			cur_it = 0;
			i++;
		}
		i = 0;
		j++;
	}
}

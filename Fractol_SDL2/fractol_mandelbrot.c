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
	int	i = 0;
	int	j = 0;
	size_t	cur_it = 0;
	char	draw = 0;
	double	cpy_init_val[2];
	const double z_r_init = 0;
	const double z_i_init = 0;

	cpy_init_val[0] = z_r_init;
	cpy_init_val[1] = z_i_init;
	while (j < e->var.win_height)
	{
		while (i < e->var.win_width)
		{
			while ((draw = fractol_calc_mb(&cpy_init_val[0], &cpy_init_val[1],
					(e->var.width_min + (e->var.width_pitch * i)), (e->var.height_max -
						(e->var.height_pitch * j))) == 0) && cur_it < e->var.iter)
				cur_it++;
			if (draw == 0)
				fractol_color_pixel(&(e->fractal), e->var.color, e->var.win_width,
					i, j, cur_it);
			cpy_init_val[0] = z_r_init;
			cpy_init_val[1] = z_i_init;
			cur_it = 0;
			draw = 0;
			i++;
		}
		i = 0;
		j++;
	}
}

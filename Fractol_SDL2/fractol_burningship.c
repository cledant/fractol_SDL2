/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_burningship.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 13:08:30 by cledant           #+#    #+#             */
/*   Updated: 2016/01/23 11:32:28 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void		fractol_burningship(t_env *e)
{
	size_t	i = 0;
	size_t	j = 0;
	size_t	cur_it = 0;
	size_t	draw = 0;
	double	cpy_init_val[2];
	const double z_r_init = 0;
	const double z_i_init = 0;

	cpy_init_val[0] = z_r_init;
	cpy_init_val[1] = z_i_init;
	while (j < e->win_height)
	{
		while (i < e->win_width)
		{
			while ((draw = fractol_calc_bs(&cpy_init_val[0], &cpy_init_val[1],
				(e->width_min + (e->width_pitch * i)), -(e->height_max -
				(e->height_pitch * j))) == 0) && cur_it < e->iter)
				cur_it++;
			if (draw == 0)
				fractol_color_pixel(&(e->fractal), e->color, e->win_width,
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

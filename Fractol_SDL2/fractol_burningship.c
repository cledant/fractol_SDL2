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
				tmp_r = fabs(z_r);
				tmp_i = fabs(z_i);
				sqrt_tmp_x = tmp_r * tmp_r;
				sqrt_tmp_y = tmp_i * tmp_i;
				z_r = (sqrt_tmp_x - sqrt_tmp_y + e->var.width_min +
					(e->var.width_pitch * i));
				z_i = tmp_r * tmp_i;
				z_i += z_i;
				z_i += -(e->var.height_max - (e->var.height_pitch * j));
				if ((res = (z_r * z_r) + (z_i * z_i)) > 400000)
					break;
				cur_it++;
			}
			if (res > 400000)
				fractol_color_pixel(&(e->fractal), e->var.color, e->var.win_width,
					i, j, cur_it);
			z_r = 0;
			z_i = 0;
			res = 0;
			cur_it = 0;
			i++;
		}
		i = 0;
		j++;
	}
}

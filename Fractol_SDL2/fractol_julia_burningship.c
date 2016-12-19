/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_burningship_julia.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 12:14:02 by cledant           #+#    #+#             */
/*   Updated: 2016/01/24 12:14:04 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"


static void	julia_set_tracking(t_env *e, double *z_r_init, double *z_i_init)
{
	if (e->var.mouse_tracking == 1)
	{
		*z_r_init = 2 * (e->var.m_width - (e->var.win_width / 2)) /
			(double)(e->var.win_width / 2);
		*z_i_init = 2 * (e->var.m_height - (e->var.win_height / 2)) /
			(double)(e->var.win_height / 2);
	}
	else
	{
		*z_r_init = 2 * (e->var.m_width_old - (e->var.win_width / 2)) /
			(double)(e->var.win_width / 2);
		*z_i_init = 2 * (e->var.m_height_old - (e->var.win_height / 2)) /
			(double)(e->var.win_height / 2);
	}
}

void		fractol_julia_burningship(t_env *e)
{
	int	i = 0;
	int	j = 0;
	size_t	cur_it = 0;
	char	draw = 0;
	double	z_r_pos = 0;
	double	z_i_pos = 0;
	double	z_r = (e->var.width_min + (e->var.width_pitch * i));
	double	z_i = (e->var.height_max - (e->var.height_pitch * j));
	double	res = 0;
	double	tmp_r = 0;
	double	tmp_i = 0;
	double	sqrt_tmp_x = 0;
	double	sqrt_tmp_y = 0;

	julia_set_tracking(e, &z_r_pos, &z_i_pos);
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
				z_r = sqrt_tmp_x - sqrt_tmp_y + z_r_pos;
				z_i = tmp_r * tmp_i;
				z_i += z_i;
				z_i += z_i_pos;
				if ((res = (z_r * z_r) + (z_i * z_i)) > 400000)
					break;
				cur_it++;
			}
			if (res > 400000)
				fractol_color_pixel(&(e->fractal), e->var.color, e->var.win_width,
					i, j, cur_it);
			cur_it = 0;
			draw = 0;
			i++;
			z_r = (e->var.width_min + (e->var.width_pitch * i));
			z_i = -(e->var.height_max - (e->var.height_pitch * j));
		}
		draw = 0;
		i = 0;
		j++;
		z_r = (e->var.width_min + (e->var.width_pitch * i));
		z_i = -(e->var.height_max - (e->var.height_pitch * j));
	}
}
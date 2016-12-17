/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 08:49:50 by cledant           #+#    #+#             */
/*   Updated: 2016/01/23 17:20:17 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	julia_set_tracking(t_env *e, double *z_r_init, double *z_i_init)
{
	if (e->mouse_tracking == 1)
	{
		*z_r_init = 2 * (e->m_width - ((int)e->win_width / 2)) /
			(double)(e->win_width / 2);
		*z_i_init = 2 * (e->m_height - ((int)e->win_height / 2)) /
			(double)(e->win_height / 2);
	}
	else
	{
		*z_r_init = 2 * (e->m_width_old - ((int)e->win_width / 2)) /
			(double)(e->win_width / 2);
		*z_i_init = 2 * (e->m_height_old - ((int)e->win_height / 2)) /
			(double)(e->win_height / 2);
	}
}

static void	julia_set_cpy_val(double *cpy_r, double *cpy_i, double z_r_init,
				double z_i_init)
{
	*cpy_r = z_r_init;
	*cpy_i = z_i_init;
}

void		fractol_julia(t_env *e)
{
	size_t	i = 0;
	size_t	j = 0;
	size_t	cur_it = 0;
	size_t	draw = 0;
	double	cpy_val[4];

	julia_set_tracking(e, &cpy_val[2], &cpy_val[3]);
	julia_set_cpy_val(&cpy_val[0], &cpy_val[1], (e->width_min + (e->width_pitch * i)),
			(e->height_max - (e->height_pitch * j)));
	while (j < e->win_height)
	{
		while (i < e->win_width)
		{
			while ((draw = fractol_calc_mb(&cpy_val[0], &cpy_val[1], cpy_val[2],
					cpy_val[3]) == 0) && cur_it < e->iter)
				cur_it++;
			if (draw == 0)
				fractol_color_pixel(&(e->fractal), e->color, e->win_width,
					i, j, cur_it);
			julia_set_cpy_val(&cpy_val[0], &cpy_val[1], (e->width_min +
				(e->width_pitch * i)), (e->height_max - (e->height_pitch * j)));
			cur_it = 0;
			draw = 0;
			i++;
		}
		draw = 0;
		i = 0;
		j++;
		julia_set_cpy_val(&cpy_val[0], &cpy_val[1], (e->width_min +
			(e->width_pitch * i)), (e->height_max - (e->height_pitch * j)));
	}
}

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

static void	julia_set_cpy_val(double *cpy_r, double *cpy_i, double z_r_init,
	double z_i_init)
{
	*cpy_r = z_r_init;
	*cpy_i = z_i_init;
}

void		fractol_julia_burningship(t_env *e)
{
	int	i = 0;
	int	j = 0;
	size_t	cur_it = 0;
	char	draw = 0;
	double	cpy_val[4];

	julia_set_tracking(e, &cpy_val[2], &cpy_val[3]);
	julia_set_cpy_val(&cpy_val[0], &cpy_val[1], (e->var.width_min + (e->var.width_pitch * i)),
		(e->var.height_max - (e->var.height_pitch * j)));
	while (j < e->var.win_height)
	{
		while (i < e->var.win_width)
		{
			while ((draw = fractol_calc_bs(&cpy_val[0], &cpy_val[1], cpy_val[2],
				cpy_val[3]) == 0) && cur_it < e->var.iter)
				cur_it++;
			if (draw == 0)
				fractol_color_pixel(&(e->fractal), e->var.color, e->var.win_width,
					i, j, cur_it);
			julia_set_cpy_val(&cpy_val[0], &cpy_val[1], (e->var.width_min +
				(e->var.width_pitch * i)), (e->var.height_max - (e->var.height_pitch * j)));
			cur_it = 0;
			draw = 0;
			i++;
		}
		draw = 0;
		i = 0;
		j++;
		julia_set_cpy_val(&cpy_val[0], &cpy_val[1], (e->var.width_min +
			(e->var.width_pitch * i)), (e->var.height_max - (e->var.height_pitch * j)));
	}
}

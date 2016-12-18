/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_pitch_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 12:48:53 by cledant           #+#    #+#             */
/*   Updated: 2016/01/20 22:47:19 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double			fractol_pitch_value(const double min, const double max,
					const int size)
{
	double		range;

	range = (min - max);
	if (range < 0)
		range = -range;
	return (range / size);
}
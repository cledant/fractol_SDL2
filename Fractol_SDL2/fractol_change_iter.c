/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_change_iter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 19:07:22 by cledant           #+#    #+#             */
/*   Updated: 2016/01/21 19:41:56 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	fractol_change_iter(t_env *e, size_t type)
{
	if (type == 0)
	{
		if (e->iter == 0)
			return ;
		else
			e->iter = e->iter - 10;
	}
	else if (type == 1)
	{
		if (e->iter == 200000)
			return ;
		else
			e->iter = e->iter + 10;
	}
	e->render = 1;
}

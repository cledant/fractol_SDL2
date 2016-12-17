/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_offset_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 13:06:45 by cledant           #+#    #+#             */
/*   Updated: 2016/01/23 18:33:02 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	fractol_offset_value(double value, int offset, double pitch)
{
	return (value + (pitch * offset));
}

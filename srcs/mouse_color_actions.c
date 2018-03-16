/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:26:51 by lazrossi          #+#    #+#             */
/*   Updated: 2018/03/16 17:15:34 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/fractol.h"
#include "../libft/includes/libft.h"
#include "../minilibx_macos/mlx.h"
#include <stdio.h>

double		square_color_range(int square_nbr)
{
	if (square_nbr == 1)
		return (32010005);
	if (square_nbr == 2)
		return (62500003);
	if (square_nbr == 3)
		return (123500006);
	if (square_nbr == 4)
		return (245005003);
	return (100000);
}

int			set_get_max_color_scale(int max_color_scale)
{
	static double color_scal = (double)(16711000) / (double)MAX_COLOR_DISTANCE;

	if (max_color_scale)
		color_scal = (double)(256 * 255 * 256) / (double)max_color_scale;
	return (color_scal);
}

double		color_range(double color)
{
	double			color_scale;
	static double	color_chosen = 0;

	if (!color)
		return (color_chosen);
	color_scale = set_get_max_color_scale(0);
	color_chosen = color * color_scale;
	return (color_chosen);
}

int			pause_julia(int activate)
{
	static int pause_mouse = 0;

	if (activate && pause_mouse)
	{
		pause_mouse = 0;
		return (0);
	}
	if (activate && !pause_mouse)
		pause_mouse = 1;
	return (pause_mouse);
}

t_complx	set_get_mouse_pos(double x, double y)
{
	static t_complx mouse_pos;

	if (x && y)
	{
		mouse_pos.r = x;
		mouse_pos.i = y;
	}
	return (mouse_pos);
}

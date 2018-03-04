/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:26:51 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/27 12:54:01 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/fractol.h"
#include "../libft/includes/libft.h"
#include "../minilibx_macos/mlx.h"

double		square_color_range(int square_center)
{
	static double color_scale = (double)(256 * 255 * 256) / (X_SIZE);
	static double color_chosen = 0;

	if (!square_center)
		return (color_chosen);
	color_chosen = square_center * color_scale;
	return (color_chosen);
}

double		color_range(double color)
{
	static double color_scale = (double)(256 * 255 * 256) / (double)MAX_COLOR_DISTANCE;
	static double color_chosen = 0;

	if (!color)
		return (color_chosen);
	color--;
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

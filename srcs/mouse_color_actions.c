/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:26:51 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/23 22:59:30 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/fractol.h"
#include "../libft/includes/libft.h"
#include "../minilibx_macos/mlx.h"
#include <math.h>

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

#include <stdio.h>
double		color_range(double color)
{
	t_color_compound	violet;
	int					iterations;
	float				time;

	violet.rgb = 0;
	if (!color)
		return (violet.rgb);
	time = color / set_get_iterations(0);
	time = sin(time);
	iterations = set_get_iterations(0);
	violet = ft_decompose_color(P_RED);
	violet.red = (int)(((float)violet.red * (float)time));
	violet.green = (int)(((float)violet.green * (float)time));
	violet.blue = (int)(((float)violet.blue * (float)time));
	violet.rgb = violet.red << 16 | violet.green << 8 | violet.blue;
	violet.rgb = violet.red << 16 | violet.green << 8 | violet.blue;
	return (violet.rgb);
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

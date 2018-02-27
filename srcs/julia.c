/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 16:33:51 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/26 15:34:39 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/includes/libft.h"
#include <math.h>
#include <stdio.h>

static int 		set_color_range(double color)
{
	double color_scale;

	color_scale = (double)(16581375) / (double)MAX_COLOR_DISTANCE;
	color = color * color_scale;
	return (color);
}

static int		suite_operation(t_complx complx_nbr, double color, t_complx suite_nbr)
{
	while (color <= MAX_COLOR_DISTANCE)
	{
		if ((suite_nbr.i * suite_nbr.i + suite_nbr.r * suite_nbr.r) > 4)
			return (set_color_range(color));
		suite_nbr = multiply_complexes(suite_nbr, suite_nbr);
		suite_nbr = add_complexes(suite_nbr, complx_nbr);
		color++;
	}
	return (0);
}

void	julia(int **screen, t_complx complx_nbr_suite)
{
	t_complx	complx_nbr;
	double		color;
	int x;
	double increment_r;
	double increment_i;
	int y;

	static double fit_screen = 4;

	fit_screen *= set_get_focus(0);
	increment_r = (double)(fit_screen / (double)X_SIZE);
	increment_i = (double)(fit_screen / (double)Y_SIZE);
	y = -1;
	complx_nbr.i = 2;
	while (++y < Y_SIZE)
	{
		complx_nbr.r = -2;
		x = -1;
		while (++x < X_SIZE)
		{
			color = 0;
			if ((color = suite_operation(complx_nbr, 0, complx_nbr_suite)))
				(*screen)[x + y * X_SIZE] = color;
			complx_nbr.r += increment_r;
		}
		complx_nbr.i -= increment_i;
	}
}

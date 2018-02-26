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


static int		suite_operation(t_complx complx_nbr, int color, t_complx suite_nbr)
{
	while (color <= MAX_COLOR_DISTANCE)
	{
		if ((suite_nbr.i * suite_nbr.i + suite_nbr.r * suite_nbr.r) > 4)
			return (color);
		suite_nbr = multiply_complexes(suite_nbr, suite_nbr);
		suite_nbr = add_complexes(suite_nbr, complx_nbr);
		color++;
	}
	return (0);
}

void	julia(int **screen, int keycode, t_complx complx_nbr_suite)
{
	t_complx	complx_nbr;
	int			color;
	int x;
	double increment_r;
	double increment_i;
	int y;

	static double fit_screen = 4;
	if (keycode == KEY_DOWN)
		fit_screen *= 0.99;
	if (keycode == KEY_UP)
		fit_screen *= 1.01;
	increment_r = (double)(fit_screen / (double)X_SIZE);
	increment_i = (double)(fit_screen / (double)Y_SIZE);
	y = -1;
	complx_nbr.i = 2;


	double color_scale;

	color_scale = 255 / MAX_COLOR_DISTANCE;
	complx_nbr_suite.i = complx_nbr_suite.i * 2 / Y_SIZE;
	complx_nbr_suite.r = complx_nbr_suite.r * 2 / X_SIZE;
	while (++y < Y_SIZE)
	{
		complx_nbr.r = -2;
		x = -1;
		while (++x < X_SIZE)
		{
			color = 0;
			if ((color = suite_operation(complx_nbr, 0, complx_nbr_suite)))
			{
				(*screen)[x + y * X_SIZE] = color * color_scale * color * color_scale * color * color_scale;
			}
			complx_nbr.r += increment_r;
		}
		complx_nbr.i -= increment_i;
	}
}

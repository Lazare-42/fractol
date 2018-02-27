/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:24:13 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/27 13:14:05 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/includes/libft.h"
#include <math.h>
#include <stdio.h>

static t_complx	multiply_complexes(t_complx a, t_complx b)
{
	t_complx result;

	if (set_get_fractal_choosen(0) == 12)
	{
		a.i = fabs(a.i);
		a.r = fabs(a.r);
		b.i = fabs(a.i);
		b.r = fabs(a.r);
	}
	result.r = a.r * b.r - a.i * b.i;
	result.i = a.r * b.i + b.r * b.i;
	return (result);
}

static t_complx	add_complexes(t_complx a, t_complx b)
{
	t_complx result;

	result.r = a.r + b.r;
	result.i = a.i + b.i;
	return (result);
}

static int		suite_operation(t_complx complx_nbr, double color,
		t_complx suite_nbr)
{
	while (color <= MAX_COLOR_DISTANCE)
	{
		if ((suite_nbr.i * suite_nbr.i + suite_nbr.r * suite_nbr.r) > 4)
			return (color_range(color));
		suite_nbr = multiply_complexes(suite_nbr, suite_nbr);
		suite_nbr = add_complexes(suite_nbr, complx_nbr);
		color++;
	}
	return (0);
}

void			fractal(int **screen, t_complx complx_nbr_suite)
{
	t_complx	complx_nbr;
	int			x;
	int			y;
	double		increment_r;
	double		increment_i;

	increment_r = (double)(get_fractal_focus() / (double)X_SIZE);
	increment_i = (double)(get_fractal_focus() / (double)Y_SIZE);
	y = -1;
	complx_nbr.i = 2;
	while (++y < Y_SIZE)
	{
		complx_nbr.r = -2;
		x = -1;
		while (++x < X_SIZE)
		{
			if ((suite_operation(complx_nbr, 0, complx_nbr_suite)))
				(*screen)[x + y * X_SIZE] = color_range(0);
			complx_nbr.r += increment_r;
		}
		complx_nbr.i -= increment_i;
	}
}

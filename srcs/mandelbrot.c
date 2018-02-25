/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 16:33:51 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/25 20:42:40 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/includes/libft.h"
#include <math.h>
#include <stdio.h>

t_complx	multiply_complexes(t_complx a, t_complx b)
{
	t_complx result;

	result.r = a.r * b.r - a.i * b.i;
	result.i = a.r * b.i + b.r * b.i;
	return (result);
}

t_complx	add_complexes(t_complx a, t_complx b)
{
	t_complx result;

	result.r = a.r + b.r;
	result.i = a.i + b.i;
	return (result);
}

static int		recurse_formula(t_complx complx_nbr, int recurse_number, t_complx suite_nbr)
{
	int module;

	module = 0;
	module = suite_nbr.i * suite_nbr.i + suite_nbr.r * suite_nbr.r;
	if (module > 4)
		return (recurse_number);
	suite_nbr = multiply_complexes(suite_nbr, suite_nbr);
	suite_nbr = add_complexes(suite_nbr, complx_nbr);
	if (recurse_number <= 200)
		return (recurse_formula(complx_nbr, ++recurse_number, suite_nbr));
	return (0);
}

void	mandelbrot(int **screen)
{
	t_complx	complx_nbr;
	t_complx	complx_nbr_suite;
	int			color;
	int x;
	double increment_r;
	double increment_i;
	int y;

	increment_r = (double)(4 / (double)X_SIZE);
	increment_i = (double)(4 / (double)Y_SIZE);
	y = -1;
	complx_nbr.i = 2;
	while (++y < Y_SIZE)
	{
		complx_nbr.r = -2;
		x = -1;
		while (++x < X_SIZE)
		{
			color = 0;
			complx_nbr_suite.i = 0;
			complx_nbr_suite.r = 0;
			if ((color = recurse_formula(complx_nbr, 0, complx_nbr_suite)))
			{
				(*screen)[x + y * X_SIZE] = 0 + color * color * (color / 10);
			}
			complx_nbr.r += increment_r;
		}
		complx_nbr.i -= increment_i;
	}
}

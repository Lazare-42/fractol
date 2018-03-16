/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complexe_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:29:22 by lazrossi          #+#    #+#             */
/*   Updated: 2018/03/16 11:29:23 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <math.h>

t_complx	multiply_complexes(t_complx a, t_complx b)
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

t_complx	add_complexes(t_complx a, t_complx b)
{
	t_complx result;

	result.r = a.r + b.r;
	result.i = a.i + b.i;
	return (result);
}

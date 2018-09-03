/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:24:13 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/26 17:06:51 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/includes/libft.h"
#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <unistd.h>
//static
int		suite_operation(t_complx suite_nbr, double color,
		t_complx complx_nbr)
{
	t_complx swap;

	if (set_get_fractal_choosen(0) == FRACTAL)
	{
		swap = suite_nbr;
		suite_nbr = complx_nbr;
		complx_nbr = swap;
	}
	while (color <= set_get_iterations(0))
	{
		if ((suite_nbr.i * suite_nbr.i + suite_nbr.r * suite_nbr.r) > 4)
			return (color_range(color));
		suite_nbr = multiply_complexes(suite_nbr, suite_nbr);
		suite_nbr = add_complexes(suite_nbr, complx_nbr);
		color++;
	}
	return (0);
}

static void		screen_line_func(void *arg)
{
	t_info			*info;
	int				x;
	int				y;
	int				size;
	int				*screen;

	info = arg;
	size = ((*info).which == BIG) ? X_SIZE - X_SIZE / 4: X_SIZE / 4;
	y = -1;
	screen = *(*info).screen;
//j	ft_printf("%d is info.y\n", (*info).y);
//	ft_printf("%d is info.x\n", (*info).x);
	while (++y < set_get_screen_lines_per_thread(0, (*info).which))
	{
		x = -1;
		while (++x < size)
		{
			screen[(*info).y + y * X_SIZE + (*info).x + x] =
				(suite_operation((*info).line[y].complx_nbr, 0,
								 (*info).complx_nbr_suite));
			(*info).line[y].complx_nbr.r += (*info).increment_r;
		}
	}
}

t_complx		set_increment_values(int which)
{
	t_complx		increment;

	increment.r = get_fractal_focus();
	increment.i = get_fractal_focus();
	if (which == BIG)
		increment.r /= (double)(X_SIZE - X_SIZE / 4);
	else
		increment.r /= (double)(X_SIZE / 4);
	if (which == BIG)
		increment.i /= (double)Y_SIZE;
	else
		increment.i /= (double)(Y_SIZE / 4);
	return (increment);
}

void			fractal(t_info info)
{
	int				y;
	t_complx		increment;
	double			increment_i_increment;

	increment = set_increment_values(info.which);
	increment_i_increment = increment.i;
	y = -1;
	info.increment_r = increment.r;
	while ((++y < Y_SIZE && info.which == BIG) || (++y < Y_SIZE / 4 && info.which == SMALL))
	{
		info.line[y].y = y;
		increment.i += increment_i_increment;
		info.line[y].complx_nbr.i = (get_fractal_focus() / 2)
			- increment.i - set_get_mouse_pos_at_zoom(0).i;
		info.line[y].complx_nbr.r = -(get_fractal_focus() / 2)
			- set_get_mouse_pos_at_zoom(0).r;
	}
	create_threads(screen_line_func, &info);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:24:13 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/24 20:27:23 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/includes/libft.h"
#include <stdio.h>
#include <pthread.h>
#include <math.h>

static int		suite_operation(t_complx suite_nbr, double color,
		t_complx complx_nbr)
{
	t_complx swap;

	if (set_get_fractal_choosen(0) == 10)
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
	t_screen_line	*screen_line;
	double			x;
	int				pixel_pos;
	static int		max_screen = X_SIZE * Y_SIZE;
	int				y;

	y = 0;
	screen_line = arg;
	while (y < set_get_screen_lines_per_thread(0))
	{
		x = -1;
		while (++x < X_SIZE - (X_SIZE / 5))
		{
			pixel_pos = (int)x + (screen_line[y].y) * X_SIZE;
			if (pixel_pos > 0 && pixel_pos < max_screen)
				(*screen_line[y].screen)[pixel_pos] =
					(suite_operation(screen_line[y].complx_nbr, 0,
									screen_line[y].complx_nbr_suite));
			screen_line[y].complx_nbr.r += screen_line->increment_r;
		}
		y++;
	}
}

void			fractal(int **screen, t_complx complx_nbr_suite, int which)
{
	int				y;
	t_complx		increment;
	t_screen_line	screen_line[Y_SIZE];
	double			increment_i_increment;

	if (which == BIG)
		increment.r = (double)(get_fractal_focus() / (double)(X_SIZE - X_SIZE / 4));
	else
		increment.r = (double)(get_fractal_focus() / (double)(X_SIZE - X_SIZE / 4));
	increment.i = (double)(get_fractal_focus() / (double)Y_SIZE);
	increment_i_increment = increment.i;
	y = -1;
	while (++y < Y_SIZE)
	{
		screen_line[y].complx_nbr_suite = complx_nbr_suite;
		screen_line[y].y = y;
		screen_line[y].screen = screen;
		screen_line[y].increment_r = increment.r;
		increment.i += increment_i_increment;
		screen_line[y].complx_nbr.i = (get_fractal_focus() / 2)
			- increment.i - set_get_mouse_pos_at_zoom(0).i;
		screen_line[y].complx_nbr.r = -(get_fractal_focus() / 2)
			- set_get_mouse_pos_at_zoom(0).r;
	}
	create_threads(screen_line_func, screen_line);
}

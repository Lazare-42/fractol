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
#include <stdio.h>
#include <pthread.h>

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

void	screen_line_test(void *arg)
{
	t_screen_line	*screen_line;
	int				x;
	screen_line = arg;
	// modify the complex number so r below
	screen_line->complx_nbr.r = -2;
	x = -1;
	while (++x < X_SIZE)
	{
		if ((suite_operation(screen_line->complx_nbr, 0, screen_line->complx_nbr_suite)))
			(*screen_line->screen)[x + (screen_line->y) * X_SIZE] = color_range(0);
		screen_line->complx_nbr.r += screen_line->increment_r;
	}
}

void	create_threads(t_screen_line *screen_line)
{
	int			y;
	pthread_t	threads[Y_SIZE];

	y = -1;
	while (++y < Y_SIZE)
		pthread_create(&threads[y], NULL, (void*)screen_line_test, &(screen_line[y]));
	y = -1;
	while (++y < Y_SIZE)
		pthread_join(threads[y], NULL);
}

void			fractal(int **screen, t_complx complx_nbr_suite)
{
	int				y;
	double			increment_r;
	double			increment_i;
	t_screen_line	screen_line[Y_SIZE];
	double			increment_i_increment;

	increment_r = (double)(get_fractal_focus() / (double)X_SIZE);
	increment_i = (double)(get_fractal_focus() / (double)Y_SIZE);
	increment_i_increment = increment_i;
	y = -1;
	while (++y < Y_SIZE)
	{
		screen_line[y].complx_nbr_suite = complx_nbr_suite;
		screen_line[y].y = y;
		screen_line[y].screen = screen;
		screen_line[y].increment_r = increment_r;
		increment_i += increment_i_increment;
		// modify the complex number so i below
		screen_line[y].complx_nbr.i = 2 - increment_i;
	}
	create_threads(screen_line);
}

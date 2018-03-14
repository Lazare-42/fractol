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
#include <math.h>

static void	screen_line_test(void *arg);

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

void			create_threads(t_screen_line *screen_line)
{
	int			y;
	pthread_t	threads[Y_SIZE];

	y = -1;
	while (++y < Y_SIZE)
		if (pthread_create(&threads[y], NULL, (void*)screen_line_test, &(screen_line[y])))
			ft_myexit("thread creation error");
	y = -1;
	while (++y < Y_SIZE)
		pthread_join(threads[y], NULL);
}

static void		screen_line_test(void *arg)
{
	t_screen_line	*screen_line;
	double			x;
	int				pixel_pos;
	static int		max_screen = X_SIZE * Y_SIZE;
	int				color;

	color = 0;
	screen_line = arg;
	x = -1;
	while (++x < X_SIZE)
	{
		if ((color = (suite_operation(screen_line->complx_nbr, 0, screen_line->complx_nbr_suite))))
			pixel_pos = (int)x + (screen_line->y) * X_SIZE;
		if (pixel_pos > 0 && pixel_pos < max_screen)
			(*screen_line->screen)[pixel_pos] = color;
		screen_line->complx_nbr.r += screen_line->increment_r;
	}
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
		screen_line[y].complx_nbr.i = (get_fractal_focus() / 2) - increment_i - set_get_mouse_pos_at_zoom(0).i;
		screen_line[y].complx_nbr.r = - (get_fractal_focus() / 2) - set_get_mouse_pos_at_zoom(0).r;
	}
	create_threads(screen_line);
}

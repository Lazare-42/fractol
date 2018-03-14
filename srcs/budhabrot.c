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
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>

static void	screen_line_test(void *arg);

static int		suite_operation(t_complx complx_nbr, double color,
		t_complx suite_nbr, t_screen_line *screen_line)
{
	double where_x;
	double where_y;
	double focus;

	focus = get_fractal_focus() / 2;
	while (color <= 200)
	{
		if ((suite_nbr.i * suite_nbr.i + suite_nbr.r * suite_nbr.r) > 4)
			return (0);
		else
		{
			where_x = (suite_nbr.i + focus) / (focus * 2);
			where_x *= X_SIZE;
			where_y = suite_nbr.r + focus;
			where_y /= focus * 2;
			where_y = (int)(where_y * Y_SIZE) * X_SIZE;
			if ((int)(where_x + where_y) > 0 && (int)(where_x + where_y) < X_SIZE * Y_SIZE)
				(*screen_line->screen)[(int)(where_x + where_y)] += 1;
		}
		suite_nbr = multiply_complexes(suite_nbr, suite_nbr);
		suite_nbr = add_complexes(suite_nbr, complx_nbr);
		color++;
	}
	return (0);
}

static void			create_threads(t_screen_line *screen_line)
{
	int			y;
	pthread_t	threads[Y_SIZE];

	y = -1;
	while (++y < set_get_core_numbers())
		if (pthread_create(&threads[y], NULL, (void*)screen_line_test, &(screen_line[y * set_get_screen_lines_per_thread(0)])))
			ft_myexit("thread creation error");
	y = -1;
	while (++y < set_get_core_numbers())
		pthread_join(threads[y], NULL);
}

static void		screen_line_test(void *arg)
{
	t_screen_line	*screen_line;
	double			x;
	int				color;
	int				y;

	y = 0;
	color = 0;
	screen_line = arg;
	while (y < set_get_screen_lines_per_thread(0))
	{
		x = -1;
		while (++x < X_SIZE)
		{
			suite_operation((screen_line[y]).complx_nbr, 0, screen_line[y].complx_nbr_suite, &(screen_line[y]));
			screen_line[y].complx_nbr.r += screen_line[y].increment_r;
		}
		y++;
	}
}

static 	t_screen_line	*create_screen_line(void)
{
	t_screen_line	*screen_line;

	screen_line = NULL;
	if (!(screen_line = malloc(sizeof(t_screen_line) * Y_SIZE)))
		ft_myexit("malloc error");
	return (screen_line);
}

void			budhabrot(int **screen, t_complx complx_nbr_suite)
{
	int						y;
	double					increment_r;
	double					increment_i;
	static t_screen_line	*screen_line = NULL;
	double					increment_i_increment;

	increment_r = (double)(get_fractal_focus() / (double)X_SIZE);
	increment_i = (double)(get_fractal_focus() / (double)Y_SIZE);
	increment_i_increment = increment_i;
	y = -1;
	if (screen_line == NULL)
		screen_line = create_screen_line();
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
	int i;
	int x;
	int max;
	int color;

	i = 0;
	max = 0;
	while (i < Y_SIZE)
	{
		x = 0;
		while (x < X_SIZE)
		{
			max = ((*screen)[x + y * X_SIZE] > max ) ? (*screen)[x + y * X_SIZE] : max;
			x++;
		}
		i++;
	}
	set_get_max_color_scale(max);
	i = 0;
	while (i < Y_SIZE)
	{
		x = 0;
		while (x < X_SIZE)
		{
			color = color_range((*screen)[x + y * X_SIZE]);
			(*screen)[x + y * X_SIZE] = color;
	//		printf("%d\n", color);
			x++;
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   budhabrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 10:14:03 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/24 03:10:35 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <pthread.h>

/*
*/

t_location	max_locaction(t_location loc, int reset)
{
	static t_location max_loc = {0, 0};
	if (max_loc.x < loc.x)
		max_loc.x = loc.x;
	if (max_loc.y < loc.y)
		max_loc.y = loc.y;
	if (reset < 0)
	{
		max_loc.x = 0;
		max_loc.y = 0;
	}

	return (max_loc);
}

static void				suite_operation(t_complx complx_nbr, double color,
		t_complx suite_nbr, t_screen_line *screen_line)
{
	t_location	loc;
	double	half_focus;
	double	focus;
	int		screen_size;

	focus = get_fractal_focus();
	half_focus = focus / 2;
	screen_size = X_SIZE * Y_SIZE;
	while (++color <= set_get_iterations(0))
	{
		if ((suite_nbr.i * suite_nbr.i + suite_nbr.r * suite_nbr.r) > 4)
			return ;
		else
		{
			loc.x = ((suite_nbr.i + half_focus) / (focus)) * X_SIZE;
			loc.y = (suite_nbr.r + half_focus) / focus;
			loc.y = (int)(loc.y * Y_SIZE) * X_SIZE;
			if ((int)(loc.x + loc.y) > 0 && (int)(loc.x + loc.y)
					< screen_size)
			{
				// ne pas acceeder a l'ecran ici mais plutot avoir un tableau statique correspondant pour ensuite appliquer la bonne palette de couleurs
				// qui depend de la distance max atteinte
				// peut aussi etre plus rapide ?
				// est necessaire car permet de
				(*screen_line->screen)[(int)(loc.x + loc.y)] += 1;
				(void)screen_line;
			}
		}
		suite_nbr = multiply_complexes(suite_nbr, suite_nbr);
		suite_nbr = add_complexes(suite_nbr, complx_nbr);
		max_locaction(loc, 0);
	}
}

static void				screen_line_func(void *arg)
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
			suite_operation((screen_line[y]).complx_nbr, 0,
					screen_line[y].complx_nbr_suite, &(screen_line[y]));
			screen_line[y].complx_nbr.r += screen_line[y].increment_r;
		}
		y++;
	}
}

static t_screen_line	*create_screen_line(void)
{
	t_screen_line	*screen_line;

	screen_line = NULL;
	if (!(screen_line = malloc(sizeof(t_screen_line) * Y_SIZE)))
		ft_myexit("malloc error");
	return (screen_line);
}

void					reaply_color(int **screen)
{
	t_color_compound	max_color;
	t_color_compound	color;
	t_location			max_loc = {0, 0};
	int					x;
	int					y;

	y = -1;
	max_loc = max_locaction(max_loc, 0);
	max_color = ft_decompose_color(max_loc.x + max_loc.y);
	while (++y < Y_SIZE)
	{
		x = -1;
		while (++x < X_SIZE)
		{
			color = ft_decompose_color((*screen)[y * Y_SIZE + x]);
			if (color.blue < 127 && color.green < 127 && color.red < 127)
			{
				color.red += 128;
				color.blue += 128;
				color.green += 128;
				color.red = color.red * color.red / max_color.red;
				color.green = color.green * color.green / max_color.green;
				color.blue =  color.blue * color.blue / max_color.blue;
			}
			else
			{
				color.red = color.red * color.red / max_color.red;
				color.green = color.green * color.green / max_color.green;
				color.blue =  color.blue * color.blue / max_color.blue;
			}
			
			color.rgb = color.red << 16 | color.green << 8 | color.blue;
			(*screen)[y * Y_SIZE + x] = color.rgb;
			//			ft_printf("%d x, %d y\n", x, y);
			/*
			   if (color.blue)
			   {
			   ft_printf("Max_color : [[red]]Red : %d[[end]] [[green]]green : %d [[end]][[blue]]blue : %d[[end]]\n", max_color.red, max_color.green, max_color.blue);
			   ft_printf("Color 	 : [[red]]Red : %d[[end]] [[green]]green : %d [[end]][[blue]]blue : %d[[end]]\n", color.red, color.green, color.blue);
			   }
			   */

		}
	}
	max_locaction(max_loc, -1);
}

void					budhabrot(int **screen, t_complx complx_nbr_suite)
{
	int						y;
	double					increment_r;
	double					increment_i;
	static t_screen_line	*screen_line = NULL;
	double					increment_i_increment;

	increment_r = (double)(get_fractal_focus() / (double)X_SIZE);
	increment_i = (double)(get_fractal_focus() / (double)Y_SIZE);
	increment_i_increment = increment_i;
	y = Y_SIZE;
	y *= -1;
	y -= 1;
	if (screen_line == NULL)
		screen_line = create_screen_line();
	while (++y < 0)
	{
		screen_line[y + Y_SIZE].complx_nbr_suite = complx_nbr_suite;
		screen_line[y + Y_SIZE].y = y;
		screen_line[y + Y_SIZE].screen = screen;
		screen_line[y + Y_SIZE].increment_r = increment_r;
		increment_i += increment_i_increment;
		screen_line[y + Y_SIZE].complx_nbr.i = (get_fractal_focus() / 2)
			- increment_i - set_get_mouse_pos_at_zoom(0).i;
		screen_line[y + Y_SIZE].complx_nbr.r = -(get_fractal_focus() / 2)
			- set_get_mouse_pos_at_zoom(0).r;
	}
	create_threads(screen_line_func, screen_line);
	reaply_color(screen);
}

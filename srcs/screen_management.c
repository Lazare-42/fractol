/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:20:25 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/26 15:20:19 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>

void		put_screen_str(int **screen, int print)
{
	int			where_to;
	static	int	max_screen_pixel = X_SIZE * Y_SIZE;
	double		*point;

	point = set_get_pixel(NULL);
	where_to = 0;
	where_to = (int)point[0] - (int)point[1] * X_SIZE;
	where_to += location_handler(0);
	if (where_to >= 0 && where_to <= max_screen_pixel)
		(*screen)[where_to] = (print) ? 0xFF400 : 0;
}

static void	put_to_screen_string(double ***object, int **screen,
		int *object_dimensions, int keycode)
{
	// we apply the object-space to null as we are not using any object
	object = NULL;
	object_dimensions = NULL;
	object = NULL;
	screen = NULL;
	keycode = 0;
	//put_screen_str(screen, print);
//	square_fractal(screen, keycode);
	//mandelbrot(screen, keycode);
}

void		print_handler(double ***tab,
		int **screen, int *dimensions, int keycode)
{
		put_to_screen_string(tab, screen, dimensions, keycode);
}

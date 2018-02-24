/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:12:38 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/24 16:48:09 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>

static	void	recurse_screen_fill(int **screen,
		int size,int start_location, int print)
{
	int new_start_location;
	int	x_center;

	x_center = start_location % X_SIZE;
	if (size / 2 > 1)
	{
		new_start_location = start_location + (size / 4) - (size / 2) * X_SIZE;
		if (new_start_location + x_center < X_SIZE)
		screen_fill(screen, size / 2,
				new_start_location, print);
		new_start_location = start_location + (size / 4) + size * X_SIZE;
		if (new_start_location + x_center < X_SIZE)
		screen_fill(screen, size / 2,
				new_start_location, print);
		new_start_location = start_location + start_location + (size) + (size / 4) * X_SIZE;
		if (new_start_location + x_center < X_SIZE)
		screen_fill(screen, size / 2,
				new_start_location, print);
		new_start_location = start_location + (size / 4) * X_SIZE - size / 2;
		if (new_start_location + x_center < X_SIZE)
		screen_fill(screen, size / 2,
				new_start_location, print);
	}
}

void			screen_fill(int **screen, int size,
		int start_location, int print)
{
	static	int	max_screen_pixel = X_SIZE * Y_SIZE;
	int			x;
	int			y;
	int			where_to;
	int			center_x;

	y = -1;
	where_to = 0;
	center_x = start_location % X_SIZE;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			if (x + center_x < X_SIZE)
			{
				where_to = x + y * X_SIZE + start_location;
				if (where_to >= 0 && where_to <= max_screen_pixel)
					(*screen)[where_to] = (print) ? set_get_color(0) : 0;
			}	
		}
	}
	set_get_color(1);
	recurse_screen_fill(screen, size, start_location, print);
}

static int				set_get_image_center(int square_size)
{

	int image_center;

	image_center = 0;
	image_center = X_SIZE / 2 + Y_SIZE / 2 * X_SIZE 
		- square_size / 3 / 2 - (square_size / 3 / 2) * X_SIZE;
	return (image_center);
}

void			square_fractal(int **screen, int print)
{
	int square_location;
	static double square_size = Y_SIZE;

	square_location = set_get_image_center(square_size);
	screen_fill(screen, square_size / 3, square_location, print);
	if (!print)
		square_size *= 1.01;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:12:38 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/26 12:38:51 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>

static	void	recurse_screen_fill(int **screen,
		int size,int start_location)
{
	int new_start_location;
	int	x_center;
	int new_center;

	new_center = size / 2;
	x_center = start_location % X_SIZE;
	if (new_center > 1)
	{
			new_start_location = start_location + (size / 4) * X_SIZE -
				new_center;
			screen_fill(screen, new_center, new_start_location);
		   new_start_location = start_location + (size) + (size / 4) * X_SIZE;
		   screen_fill(screen, new_center, new_start_location);
		   new_start_location = start_location + (size / 4) - (new_center)
			   * X_SIZE;
		   screen_fill(screen, new_center, new_start_location);
		   new_start_location = start_location + (size / 4) + size * X_SIZE;
		   screen_fill(screen, new_center, new_start_location);
	}
}

void			screen_fill(int **screen, int size, int start_location)
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
			where_to = x + y * X_SIZE + start_location;
			if (where_to >= 0 && where_to <= max_screen_pixel)
				(*screen)[where_to] = set_get_color(0);
		}
	}
	set_get_color(1);
	recurse_screen_fill(screen, size, start_location);
}

static int				set_get_image_center(int square_size)
{

	int image_center;

	image_center = 0;
	image_center = X_SIZE / 2 + Y_SIZE / 2 * X_SIZE 
		- square_size / 3 / 2 - (square_size / 3 / 2) * X_SIZE;
	return (image_center);
}

void			square_fractal(int **screen)
{
	int square_location;
	static double square_size = Y_SIZE;

	square_location = set_get_image_center(square_size);
	screen_fill(screen, square_size / 3, square_location);
}

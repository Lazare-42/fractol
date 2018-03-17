/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:12:38 by lazrossi          #+#    #+#             */
/*   Updated: 2018/03/16 17:49:18 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <stdio.h>

static	void	recurse_screen_fill(int **screen,
		int size, int start_location)
{
	static int	recurse_number = 0;
	int			new_start_location;
	int			x_center;
	int			new_center;

	recurse_number++;
	new_center = size / 2;
	x_center = start_location % X_SIZE;
	if (new_center > 1)
	{
		new_start_location = start_location + (size / 4) * X_SIZE -
			new_center;
		screen_fill(screen, new_center, new_start_location, 1);
		new_start_location = start_location + (size) + (size / 4) * X_SIZE;
		screen_fill(screen, new_center, new_start_location, 2);
		new_start_location = start_location + (size / 4) - (new_center)
			* X_SIZE;
		screen_fill(screen, new_center, new_start_location, 3);
		new_start_location = start_location + (size / 4) + size * X_SIZE;
		screen_fill(screen, new_center, new_start_location, 4);
	}
}

void			screen_fill(int **screen, int size, int start_location,
		int sqrt)
{
	static	int	max_screen_pixel = X_SIZE * Y_SIZE;
	int			x;
	int			y;
	int			where_to;

	y = -1;
	where_to = 0;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			where_to = x + y * X_SIZE + start_location;
			if (where_to >= 0 && where_to <= max_screen_pixel)
				(*screen)[where_to] = (!(*screen)[where_to]) ?
					square_color_range(sqrt) : 0;
		}
	}
	recurse_screen_fill(screen, size, start_location);
}

static int		set_get_image_center(int square_size)
{
	int image_center;

	image_center = 0;
	image_center = X_SIZE / 2 + Y_SIZE / 2 * X_SIZE
		- square_size / 3 / 2 - (square_size / 3 / 2) * X_SIZE;
	return (image_center);
}

void			square_fractal(int **screen)
{
	int				square_location;
	double			square_size;
	int				change_image;
	static int		first = 1;

	change_image = Y_SIZE;
	square_size = Y_SIZE;
	if (!first)
	{
		change_image = set_get_focus(0);
		if (change_image == square_size)
			return ;
	}
	first = 0;
	square_size *= set_get_focus(0) / 4;
	square_location = set_get_image_center(square_size);
	screen_fill(screen, square_size / 3, square_location, 0);
}

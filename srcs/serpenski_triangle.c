/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serpenski_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 19:10:31 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/24 15:06:52 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>

// il faut non pas transformer lecran mais appliquer une transformation sur chaque point de l'espace (== fonction inverse)

// bon en gros tas juste les dimensions d'un espace que tu transformes et ensuite tu  normes cet espace
//
static	void	screen_fill(int **screen, int width, int height, int start_location);

static	void	recurse_screen_fill(int **screen, int width, int height, int start_location)
{
	if (height / 2 > 1)
	{
		screen_fill(screen, height / 2, width / 2, start_location + (width / 4) - (height / 2) * X_SIZE);
		screen_fill(screen, height / 2, width / 2, start_location + (width / 4) + height * X_SIZE);
		screen_fill(screen, height / 2, width / 2, start_location + (width) + (height / 4) * X_SIZE);
		screen_fill(screen, height / 2, width / 2, start_location + (height / 4) * X_SIZE - width / 2);
	}
}

static	void	screen_fill(int **screen, int width, int height, int start_location)
{
	static	int black_or_white = 0xFF400;
	static	int	max_screen_pixel = X_SIZE * Y_SIZE;
	int 		x;
	int 		y;
	int 		where_to;
	int 		stop;

	x = 0;
	y = 0;
	where_to = 0;
	stop = height * width;
	while (y < height)
	{
		while (x < width)
		{
			where_to = x + y * X_SIZE + start_location;
			if (where_to >= 0 && where_to <= max_screen_pixel)
				(*screen)[where_to] = black_or_white;
			x++;
		}
		x = 0;
		y++;
	}
	black_or_white += 1000;
	recurse_screen_fill(screen, width, height, start_location);
}

void	square_fractal(int **screen)
{
	int square_location;

	square_location = 0;
	square_location = location_handler(0);
	square_location -= Y_SIZE / 3 / 2;
	square_location -= (Y_SIZE / 3 / 2) * X_SIZE;
	screen_fill(screen, Y_SIZE / 3, Y_SIZE / 3, square_location);
}

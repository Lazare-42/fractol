/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:00:05 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/24 16:33:49 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/fractol.h"
#include "../libft/includes/libft.h"
#include "../minilibx_macos/mlx.h"
#include <stdio.h>

t_mlx		set_get_mlx(t_mlx *mlx)
{
	static t_mlx mlx_linker;

	if (mlx)
		mlx_linker = *mlx;
	return (mlx_linker);
}

t_complx	set_get_mouse_pos(double x, double y)
{
	static t_complx mouse_pos;

	if (x && y)
	{
		mouse_pos.r = x;
		mouse_pos.i = y;
	}
	return (mouse_pos);
}

void	fractal_handler(int fractal_number)
{
	static int fractal_number_choosen = 0;
	static	int erase = X_SIZE * Y_SIZE * 4;
	t_mlx	mlx;

	if (fractal_number)
	{
		fractal_number_choosen = fractal_number;
		return ;
	}
	mlx = set_get_mlx(NULL);
	ft_bzero(mlx.screen_data, erase);
	if (fractal_number_choosen == 5)
		julia(&(mlx.screen_data), set_get_mouse_pos(0, 0));
	else if (fractal_number_choosen == 10)
		mandelbrot(&(mlx.screen_data));
	else if (fractal_number_choosen == 6)
		square_fractal(&(mlx.screen_data));
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.image, 0, 0);
}

int		set_get_color(int change)
{
	static	int black_or_white = 0xFF400;
	if (change)
		black_or_white += 100;
	
	return (black_or_white);
}

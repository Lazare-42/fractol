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

int		pause_julia(int activate)
{
	static int pause_mouse = 0;

	if (activate && pause_mouse)
	{
		pause_mouse = 0;
		return (0);
	}
	if (activate && !pause_mouse)
		pause_mouse = 1;
	return (pause_mouse);
}

t_mlx		set_get_mlx(t_mlx *mlx)
{
	static t_mlx mlx_linker;

	if (mlx)
		mlx_linker = *mlx;
	return (mlx_linker);
}

double	set_get_focus(int sign)
{
	static double focus = 1;

	if (!sign)
		return (focus);
	if (sign < 0)
		focus = (double)0.99;
	if (sign > 0)
		focus = (double)1.01;
	return (focus);
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

int		set_get_fractal_choosen(int fractal_number)
{
	static int fractal_number_choosen = 0;

	if (fractal_number)
	{
		fractal_number_choosen = fractal_number;
		return (0);
	}
	return (fractal_number_choosen);
}

void	fractal_handler(void)
{
	static int fractal_number_choosen = 0;
	static	int erase = X_SIZE * Y_SIZE * 4;
	t_mlx	mlx;

	fractal_number_choosen = (!fractal_number_choosen) ?
		set_get_fractal_choosen(0) : fractal_number_choosen;
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

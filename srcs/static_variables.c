/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:00:05 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/27 13:07:42 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/fractol.h"
#include "../libft/includes/libft.h"
#include "../minilibx_macos/mlx.h"

t_mlx	set_get_mlx(t_mlx *mlx)
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
		focus = (double)0.9;
	if (sign > 0)
		focus = (double)1.1;
	return (focus);
}

double	get_fractal_focus(void)
{
	static double fit_screen = 4;

	fit_screen *= set_get_focus(0);
	return (fit_screen);
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

int		loop_fractal(int necessary)
{
	(void)necessary;
	fractal_handler();
	return (1);
}

void	fractal_handler(void)
{
	static int		fractal_number_choosen = 0;
	static int		erase = X_SIZE * Y_SIZE * 4;
	static t_complx	mandelbrot_burningship = {0, 0, 0};
	t_mlx			mlx;

	fractal_number_choosen = (!fractal_number_choosen) ?
		set_get_fractal_choosen(0) : fractal_number_choosen;
	mlx = set_get_mlx(NULL);
	ft_bzero(mlx.screen_data, erase);
	if (fractal_number_choosen == 5)
		fractal(&(mlx.screen_data), set_get_mouse_pos(0, 0));
	else if (fractal_number_choosen == 10)
		fractal(&(mlx.screen_data), mandelbrot_burningship);
	else if (fractal_number_choosen == 6)
		square_fractal(&(mlx.screen_data));
	else if (fractal_number_choosen == 12)
		fractal(&(mlx.screen_data), mandelbrot_burningship);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.image, 0, 0);
	put_fps();
}

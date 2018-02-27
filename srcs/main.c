/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:07:08 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/26 17:05:37 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "../libft/includes/libft.h"
#include "../includes/mlx_keycode.h"
#include <unistd.h>
#include "../includes/fractol.h"
#include <stdlib.h>
#include <stdio.h>

static int		draw(void);

static	t_mlx	my_mlx_init(void)
{
	t_mlx	mlx;
	int		bpp;
	int		endian;
	int		size_line;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, X_SIZE, Y_SIZE, "FDF");
	mlx.image = mlx_new_image(mlx.mlx, X_SIZE, Y_SIZE);
	mlx.screen_data = (int*)mlx_get_data_addr(mlx.image,
			&bpp, &size_line, &endian);
	set_get_mlx(&mlx);
	fractal_handler(0);
	return (mlx);
}

static int 		keycode_func(int keycode, int b)
{
	(void)b;
	if (keycode == 53)
		exit(0);
	return (1);
}

static int		mouse_func(int x, int y, int b)
{
	(void)b;
	double x_zoom;
	double y_zoom;

	x_zoom = (double)(x - X_SIZE / 2) / X_SIZE;
	y_zoom = (double)(y - Y_SIZE / 2) / Y_SIZE;
	set_get_mouse_pos(x_zoom, y_zoom);
	fractal_handler(0);
	return (1);
}

static int		draw(void)
{
	static t_mlx mlx;
	static	int initalize = 0;

	if (!initalize)
	{
		mlx = my_mlx_init();
		initalize = 1;
	}
	mlx_mouse_hook(mlx.win, mouse_func, 0);
	mlx_hook(mlx.win, KEYPRESS, KEYRELEASE, keycode_func, 0);
	mlx_hook(mlx.win, MOTIONNOTIFY, MOTIONNOTIFY, mouse_func, 0);
	mlx_loop(mlx.mlx);
	return (0);
}

int				main(int ac, char **av)
{
	int arg_len;

	arg_len = 0;
	if (ac < 2)
		ft_myexit("Not enough arguments");
	if (ac > 2)
		ft_myexit("Too many arguments");
	arg_len = ft_strlen(av[1]);
	if (arg_len != 6 && arg_len != 5 && arg_len != 10)
		ft_myexit("Unrecognized option. Pass julia, square, mandelbrot.");
	if (arg_len == 5 && ft_memcmp(av[1], "julia", 5))
		ft_myexit("Unrecognized option. Pass julia, square, mandelbrot.");
	if (arg_len ==  10 && ft_memcmp(av[1], "mandelbrot", 10))
		ft_myexit("Unrecognized option. Pass julia, square, mandelbrot.");
	if (arg_len ==  6 && ft_memcmp(av[1], "square", 6))
		ft_myexit("Unrecognized option. Pass julia, square, mandelbrot.");
	fractal_handler(arg_len);
	draw();
	return (0);
}

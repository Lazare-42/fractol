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
	print_handler(store_tab(NULL), &(mlx.screen_data), 0, mlx.keycode);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.image, 0, 0);
	return (mlx);
}

static int 		keycode_func(int keycode, t_mlx *mlx)
{
	static	int erase = X_SIZE * Y_SIZE * 4;

	if (keycode == 53)
		exit(0);
	if (keycode)
	{
		ft_bzero(mlx->screen_data, erase);
		print_handler(store_tab(NULL), &(mlx->screen_data), 0, keycode);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image, 0, 0);
	}
	return (1);
}

static int		mouse_func(int button, int x, int y, t_mlx *mlx)
{
	(void)button;
	(void)mlx;
	int keycode;
	t_complx complx_nbr_suite;

	keycode = 0;
	complx_nbr_suite.i = x;
	complx_nbr_suite.r = y;
	static int erase = X_SIZE * Y_SIZE * 4;
	ft_bzero(mlx->screen_data, erase);
	//	print_handler(store_tab(NULL), &(mlx->screen_data), 0, keycode);
	julia(&(mlx->screen_data), keycode, complx_nbr_suite);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image, 0, 0);
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
	//	mlx_key_hook(mlx.win, keycode_func, (void*)&mlx);
	mlx_mouse_hook(mlx.win, mouse_func, (void*)&mlx);
	mlx_hook(mlx.win, KEYPRESS, KEYRELEASE, keycode_func, (void*)&mlx);
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
	ft_putnbr(arg_len);
	if (arg_len == 5 && ft_memcmp(av[1], "julia", 5))
		ft_myexit("Unrecognized option. Pass julia, squares, mandelbrot.");
	if (arg_len ==  10 && ft_memcmp(av[1], "mandelbrot", 10))
		ft_myexit("Unrecognized option. Pass julia, squares, mandelbrot.");
	if (arg_len ==  6 && ft_memcmp(av[1], "square", 6))
		ft_myexit("Unrecognized option. Pass julia, squares, mandelbrot.");
	if (arg_len != 6 && arg_len != 5 && arg_len != 10)
		ft_myexit("Unrecognized option. Pass julia, squares, mandelbrot.");
	draw();
	return (0);
}

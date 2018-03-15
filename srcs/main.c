/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:07:08 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/27 13:17:26 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "../libft/includes/libft.h"
#include "../includes/mlx_keycode.h"
#include <unistd.h>
#include "../includes/fractol.h"
#include <stdlib.h>
#include <stdio.h>

static	t_mlx	my_mlx_init(void)
{
	t_mlx	mlx;
	int		bpp;
	int		endian;
	int		size_line;

	if (!(mlx.mlx = mlx_init()))
		ft_myexit("malloc error");
	if (!(mlx.win = mlx_new_window(mlx.mlx, X_SIZE, Y_SIZE, "Fract'ol")))
		ft_myexit("malloc error");
	if (!(mlx.image = mlx_new_image(mlx.mlx, X_SIZE, Y_SIZE)))
		ft_myexit("malloc error");
	if (!(mlx.screen_data = (int*)mlx_get_data_addr(mlx.image,
			&bpp, &size_line, &endian)))
		ft_myexit("malloc error");
	set_get_mlx(&mlx);
	fractal_handler();
	return (mlx);
}

static int		draw(void)
{
	static	t_mlx	mlx;
	static	int		initalize = 0;

	if (!initalize)
	{
		mlx = my_mlx_init();
		initalize = 1;
	}
	mlx_mouse_hook(mlx.win, mouse_zoom, 0);
	mlx_hook(mlx.win, KEYPRESS, KEYRELEASE, keycode_func, 0);
	mlx_hook(mlx.win, MOTIONNOTIFY, MOTIONNOTIFY, mouse_func, 0);
	mlx_loop_hook(mlx.mlx, loop_fractal, 0);
	mlx_loop(mlx.mlx);
	return (0);
}

static void		unrecognized_option(void)
{
	ft_putstr_fd("Unrecognized option. Pass just one option : julia,", 2);
	ft_myexit(" square, mandelbrot, budhabrot or burning_ship.");
}

int				main(int ac, char **av)
{
	int arg_len;

	set_get_screen_lines_per_thread(set_get_core_numbers());
	arg_len = 0;
	if (ac < 2)
		unrecognized_option();
	if (ac > 2)
		unrecognized_option();
	arg_len = ft_strlen(av[1]);
	if (arg_len != 6 && arg_len != 5 && arg_len != 10 && arg_len != 12 && arg_len != 9)
		unrecognized_option();
	if (arg_len == 5 && ft_memcmp(av[1], "julia", 5))
		unrecognized_option();
	if (arg_len == 10 && ft_memcmp(av[1], "mandelbrot", 10))
		unrecognized_option();
	if (arg_len == 6 && ft_memcmp(av[1], "square", 6))
		unrecognized_option();
	if (arg_len == 12 && ft_memcmp(av[1], "burning_ship", 12))
		unrecognized_option();
	if (arg_len == 9 && ft_memcmp(av[1], "budhabrot", 9))
		unrecognized_option();
	set_get_fractal_choosen(arg_len);
	draw();
	return (0);
}

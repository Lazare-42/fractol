/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:07:08 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/26 13:52:15 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "../libft/includes/libft.h"
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

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, X_SIZE, Y_SIZE, "FDF");
	mlx.image = mlx_new_image(mlx.mlx, X_SIZE, Y_SIZE);
	mlx.screen_data = (int*)mlx_get_data_addr(mlx.image,
			&bpp, &size_line, &endian);
	mlx_key_hook(mlx.win, key_action, &mlx);
	mlx_loop(mlx.mlx);
	return (mlx);
}
 
static int		key_action(t_mlx *mlx)
{
	static int erase_size = X_SIZE * Y_SIZE * 4;

	debug();
	ft_putnbr(mlx->keycode);
	ft_putchar('\n');
	if (mlx->keycode == 53)
		exit(0);
	if (mlx->keycode != 53)
	{
	debug();
		ft_bzero((void*)(mlx->screen_data), erase_size);
	debug();
		print_handler(store_tab(NULL), &(mlx->screen_data), 0, mlx->keycode);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image, 0, 0);
	}
	return (1);
}

static int		draw(void)
{
	static int		inititialize = 0;
	static t_mlx	mlx;

	if (!inititialize)
	{
		mlx = my_mlx_init();
		inititialize = 1;
	}
	mlx.keycode = 0;
	print_handler(store_tab(NULL), &(mlx.screen_data), 0, 0);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.image, 0, 0);
	ft_putnbr(mlx.keycode);
	return (0);
}

int				main(void)
{
	double	***tab;

	tab = NULL;
	draw();
	return (0);
}

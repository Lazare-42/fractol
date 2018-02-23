/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:07:08 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/23 10:49:26 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "../libft/includes/libft.h"
#include <unistd.h>
#include "../includes/fractol.h"
#include <stdlib.h>
#include <stdio.h>

static	t_mlx	*my_mlx_init(void)
{
	t_mlx	*mlx;
	int		bpp;
	int		endian;
	int		size_line;

	mlx = NULL;
	if (!(mlx = malloc(sizeof(t_mlx))))
		ft_myexit("malloc_error");
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, X_SIZE, Y_SIZE, "FDF");
	mlx->image = mlx_new_image(mlx->mlx, X_SIZE, Y_SIZE);
	mlx->screen_data = (int*)mlx_get_data_addr(mlx->image,
			&bpp, &size_line, &endian);
	return (mlx);
}

static int		draw(int keycode)
{
	static t_mlx *mlx = NULL;

	if (!mlx)
		mlx = my_mlx_init();
	printf("%d\n", keycode);
	if (keycode == 53)
		exit(0);
	/*
	if (keycode)
	{
		print_handler(store_tab(NULL), 0, &(mlx->screen_data), dimensions);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image, 0, 0);
		store_tab(table_transform_handler(store_tab(NULL), keycode));
	}
	*/
//	print_handler(store_tab(NULL), 1, &(mlx->screen_data), dimensions);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image, 0, 0);
	mlx_key_hook(mlx->win, draw, 0);
	mlx_loop(mlx->mlx);
	return (0);
}

int				main(void)
{
	int		keycode;
	double	***tab;

	keycode = 0;
	tab = NULL;
	draw(0);
	return (0);
}

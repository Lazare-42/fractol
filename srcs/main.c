/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:07:08 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/22 11:49:38 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "../libft/includes/libft.h"
#include <unistd.h>
#include "../includes/fdf.h"
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

static int		draw(int keycode, int *dimensions)
{
	static t_mlx *mlx = NULL;

	if (!mlx)
		mlx = my_mlx_init();
	if (keycode == 53)
		exit(0);
	if (keycode)
	{
		print_handler(store_tab(NULL), 0, &(mlx->screen_data), dimensions);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image, 0, 0);
		store_tab(table_transform_handler(store_tab(NULL), keycode));
	}
	print_handler(store_tab(NULL), 1, &(mlx->screen_data), dimensions);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image, 0, 0);
	mlx_key_hook(mlx->win, draw, dimensions);
	mlx_loop(mlx->mlx);
	return (0);
}

int				main(int ac, char **av)
{
	int		*dimensions;
	int		keycode;
	double	***tab;

	keycode = 0;
	tab = NULL;
	dimensions = NULL;
	(void)ac;
	if (av[1])
	{
		if (!(tab = ft_parsing(av[1], &dimensions)))
			return (ft_put_fatal_error("Parsing error."));
	}
	else
		return (ft_put_fatal_error(("Pass a file to FDF to launch program")));
	tab = store_tab(tab);
	draw(0, dimensions);
	return (0);
}

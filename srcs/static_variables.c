/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:00:05 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/24 20:19:07 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/fractol.h"
#include "../libft/includes/libft.h"
#include "../minilibx_macos/mlx.h"
#include <stdio.h>

t_mlx	set_get_mlx(t_mlx *mlx)
{
	static t_mlx mlx_linker;

	if (mlx)
		mlx_linker = *mlx;
	return (mlx_linker);
}

int		set_get_iterations(int action)
{
	static	int	iterations = INIT_COLOR_DISTANCE;

	if (!action)
		return (iterations);
	if (action == 1)
		iterations += 10;
	else
		iterations -= 10;
	return (action);
}

double	set_get_focus(int sign)
{
	static double focus = 4;

	if (!sign)
		return (focus);
	if (sign < 0)
		focus *= (double)(ZOOM_OUT);
	if (sign > 0)
		focus *= (double)(ZOOM_IN);
	return (focus);
}

double	get_fractal_focus(void)
{
	static double fit_screen = 1;

	fit_screen = set_get_focus(0);
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

void put_info(t_mlx mlx)
{
	char	fps_str[20];
	char		*nbr;
	static int	fps;
	int			tmp;


	nbr = NULL;
	if ((tmp = put_fps()) != -1)
			fps = tmp;
	if (!(nbr = ft_itoa(fps)))
		return ;
	ft_memset((void*)fps_str, 0, 10);
	ft_memcpy((void*)fps_str, "FPS : ", 6);
	ft_memcpy((void*)&fps_str[6], nbr, ft_strlen(nbr));
	ft_memdel((void**)&nbr);
	mlx_string_put(mlx.mlx, mlx.win,
			X_SIZE - (X_SIZE / 4),
			0, GREY, (char*)fps_str);
}

void	fractal_handler(void)
{
	static int		fractal_number_choosen = 0;
	static int		erase = X_SIZE * Y_SIZE * 4;
	static t_complx	first_complx = {0, 0, 0};
	t_mlx			mlx;


	fractal_number_choosen = (!fractal_number_choosen) ?
		set_get_fractal_choosen(0) : fractal_number_choosen;
	mlx = set_get_mlx(NULL);
	ft_bzero(mlx.screen_data, erase);
	if (fractal_number_choosen == JULIA)
		if (!pause_julia(0))
			first_complx = set_get_mouse_pos(0, 0);
	//	printf("%f is i, %f is r\n", first_complx.i, first_complx.r);
	if (fractal_number_choosen == JULIA)
		fractal(&(mlx.screen_data), first_complx);
	else if (fractal_number_choosen == FRACTAL)
		fractal(&(mlx.screen_data), first_complx);
	else if (fractal_number_choosen == SQUARE)
		square_fractal(&(mlx.screen_data));
	else if (fractal_number_choosen == BUDHA)
		budhabrot(&(mlx.screen_data), first_complx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.image, 0, 0);
	put_info(mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:15:15 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/25 14:51:31 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/fractol.h"
#include "../libft/includes/libft.h"
#include <stdio.h>

int	keycode_func(int keycode, int b)
{
	(void)b;
	if (keycode == ESC)
		exit(0);
	else if (keycode == SPACE_BAR)
		pause_julia(1);
	else if (keycode == PLUS || keycode == P)
		set_get_iterations(1);
	else if (keycode == MINUS || keycode == M)
		set_get_iterations(-1);
//	ft_printf("%d\n is key touched", keycode);
	return (1);
}
#include <stdio.h>
int	mouse_func(int x, int y, int b)
{
	double x_zoom;
	double y_zoom;
	double focus;
	static	int	difference_x = 0;
	static	int	difference_y = 0;

	(void)b;
	if (!difference_x && !difference_y)
	{
		difference_x = X_SIZE / 4;
		difference_y = Y_SIZE / 4;
	}
	if ((x < X_SIZE - difference_x) || (y < Y_SIZE - difference_y))
		return (1);
	focus = get_fractal_focus();
	x -= difference_x + X_SIZE / 8;
	y -= difference_y + Y_SIZE / 8;
	x_zoom = (double)(x / (double)(X_SIZE) - 0.5) * focus * (double)4;
	y_zoom = (y / (double)(Y_SIZE) - 0.5) * focus * (double)4;
	y_zoom *= (double)-1;
	set_get_mouse_pos(x_zoom, y_zoom);
	return (1);
}

int	mouse_zoom(int button, int x, int y, int b)
{
	(void)b;
	if (button == 4 || button == 5)
		set_get_mouse_pos_at_zoom(-1);
	if (button == 4)
		set_get_focus(-1);
	if (button == 5)
		set_get_focus(1);
	if (button == 4 || button == 5)
		set_get_mouse_pos_at_zoom(1);
	(void)x;
	(void)y;
	return (1);
}

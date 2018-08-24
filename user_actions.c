/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:15:15 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/24 00:01:33 by lazrossi         ###   ########.fr       */
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
	else if (keycode == KEY_UP)
		get_move_screen(0.2, 0);
	else if (keycode == KEY_LEFT)
		get_move_screen(0.0, -0.2);
	else if (keycode == KEY_RIGHT)
		get_move_screen(0, 0.2);
	else if (keycode == KEY_DOWN)
		get_move_screen(-0.2, 0);
//	ft_printf("%d\n is key touched", keycode);
	return (1);
}

int	mouse_func(int x, int y, int b)
{
	double x_zoom;
	double y_zoom;
	double focus;

	(void)b;
	focus = 0;
	focus = get_fractal_focus();
	x_zoom = (double)(x / (double)X_SIZE - 0.5) * focus;
	y_zoom = -1 * (y / (double)Y_SIZE - 0.5) * focus;
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

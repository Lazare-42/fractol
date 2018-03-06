/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:15:15 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/27 11:20:35 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/fractol.h"
#include "../libft/includes/libft.h"
#include <stdio.h>

int	keycode_func(int keycode, int b)
{
	(void)b;
	if (keycode == 53)
		exit(0);
	if (keycode == 49)
		pause_julia(1);
	return (1);
}

int	mouse_func(int x, int y, int b)
{
	double x_zoom;
	double y_zoom;
	double focus;

	(void)b;
	focus = 0;
	if (pause_julia(0))
		return (1);
	focus = get_fractal_focus() / 2;
	x_zoom = (double)(x / (double)X_SIZE - 0.5) * focus;
	y_zoom = -1 * (y / (double)Y_SIZE - 0.5) *  focus;
	set_get_mouse_pos(x_zoom, y_zoom);
	return (1);
}

int	mouse_zoom(int button, int x, int y, int b)
{
	(void)b;
	if (button == 4)
		set_get_focus(-1);
	if (button == 5)
		set_get_focus(1);
	(void)x;
	(void)y;
	return (1);
}

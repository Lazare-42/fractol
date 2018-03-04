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

	if (pause_julia(0))
		return (1);
	(void)b;
	x_zoom = (double)(x - X_SIZE / 2) * 4 / X_SIZE;
	y_zoom = (double)(y - Y_SIZE / 2) * 4 / Y_SIZE;
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

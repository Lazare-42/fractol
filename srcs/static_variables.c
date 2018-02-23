/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:00:05 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/22 12:51:42 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/fdf.h"
#include "../libft/includes/libft.h"

double	*set_get_pixel(double *new_point)
{
	static double *point = NULL;

	if (!point)
	{
		if (!(point = malloc(sizeof(double) * 3)))
			return (NULL);
		point[0] = 0;
		point[1] = 0;
		point[2] = 0;
	}
	else if (new_point)
		point = new_point;
	return (point);
}

double	*set_get_cos_sinus(double *new_cos_sinus)
{
	static double *cos_sinus = NULL;

	if (!cos_sinus)
	{
		if (!(cos_sinus = (double*)malloc(sizeof(double) * 6)))
			return (NULL);
		(cos_sinus)[0] = 1;
		(cos_sinus)[1] = 0;
		(cos_sinus)[2] = 1;
		(cos_sinus)[3] = 0;
		(cos_sinus)[4] = 1;
		(cos_sinus)[5] = 0;
	}
	else if (new_cos_sinus)
		cos_sinus = new_cos_sinus;
	return (cos_sinus);
}

double	*set_get_radiuses(double *new_radiuses)
{
	static double *radiuses = NULL;

	if (!radiuses)
	{
		if (!(radiuses = (double*)malloc(sizeof(double) * 3)))
			return (NULL);
	}
	else if (new_radiuses)
		radiuses = new_radiuses;
	return (radiuses);
}

int		location_handler(int input_operation)
{
	static int width = X_SIZE / 2;
	static int height = Y_SIZE / 2 * X_SIZE;
	static int camera_center = X_SIZE / 2 + Y_SIZE / 2 * X_SIZE;

	if (!input_operation)
		return (camera_center);
	if (input_operation == KEY_LEFT)
		width -= X_SIZE / 20;
	if (input_operation == KEY_RIGHT)
		width += X_SIZE / 20;
	if (input_operation == KEY_UP)
		height += Y_SIZE / 20 * X_SIZE;
	if (input_operation == KEY_DOWN)
		height -= Y_SIZE / 20 * X_SIZE;
	camera_center = width + height;
	return (camera_center);
}

double	***store_tab(double ***tabtab)
{
	static double ***tab = NULL;

	if (tabtab)
		tab = tabtab;
	return (tab);
}

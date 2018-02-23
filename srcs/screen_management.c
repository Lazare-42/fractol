/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:20:25 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/23 13:10:49 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>

void		put_screen_str(int **screen, int print)
{
	int			where_to;
	static	int	max_screen_pixel = X_SIZE * Y_SIZE;
	double		*point;

	point = set_get_pixel(NULL);
	where_to = 0;
	where_to = (int)point[0] - (int)point[1] * X_SIZE;
	where_to += location_handler(0);
	if (where_to >= 0 && where_to <= max_screen_pixel)
		(*screen)[where_to] = (print) ? 0xFF400 : 0;
}

static void	put_to_screen_string(double ***tab, int **screen,
		int print, int *dimensions)
{
	int			i;
	int			j;

	i = -1;
	tab = matrix_multiplication(tab, dimensions);
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			put_screen_str(screen, print);
		}
	}
}

void		print_handler(double ***tab,
		int print, int **screen, int *dimensions)
{
	if (print)
		put_to_screen_string(tab, screen, 1, dimensions);
	else
		put_to_screen_string(tab, screen, 0, dimensions);
}

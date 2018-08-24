/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames_per_seconds.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:32:20 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/24 20:21:05 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "../libft/includes/libft.h"
#include "../includes/fractol.h"
#include <stdio.h>

int		put_fps(void)
{
	static time_t	launchtime = 0;
	time_t			time_since;
	static int		fps = 0;

	if (!launchtime)
	{
		if (!(time(&launchtime)))
			return (ERROR);
		return (0);
	}
	if (!(time(&time_since)))
		return (ERROR);
	fps++;
	if (time_since != launchtime)
	{
		if (time_since - launchtime == 1)
			return (fps);
		fps = 0;
		time(&launchtime);
	}
	return (-1);
}

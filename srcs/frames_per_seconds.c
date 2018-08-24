/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames_per_seconds.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:32:20 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/24 19:47:01 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "../libft/includes/libft.h"
#include <stdio.h>

int		put_fps(void)
{
	static time_t	launchtime = 0;
	time_t			time_since;
	static int		fps = 0;
	char			*itoa;

	if (!launchtime)
	{
		if (!(time(&launchtime)))
			return (-1);
		return (-1);
	}
	if (!(time(&time_since)))
		return (-1);
	if (time_since != launchtime)
	{
		if (time_since - launchtime == 1)
		{
			if (!(itoa = ft_itoa(fps)))
				return (fps);
		}
		else
			return (0);
		time(&launchtime);
		fps = 0;
	}
	fps++;
	return (-1);
}

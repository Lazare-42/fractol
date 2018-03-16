/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames_per_seconds.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:32:20 by lazrossi          #+#    #+#             */
/*   Updated: 2018/03/16 11:35:04 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "../libft/includes/libft.h"
#include <stdio.h>

void	put_fps(void)
{
	static time_t	launchtime = 0;
	time_t			time_since;
	static int		fps = 0;

	if (!launchtime)
	{
		if (!(time(&launchtime)))
			return ;
		return ;
	}
	if (!(time(&time_since)))
		return ;
	if (time_since != launchtime)
	{
		if (time_since - launchtime == 1)
		{
			ft_putnbr((int)(fps));
			ft_putstr(" FPS\n");
		}
		else
			ft_putstr("FPS < 1\n");
		time(&launchtime);
		fps = 0;
	}
	fps++;
}

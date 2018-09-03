/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:39:01 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/26 17:19:14 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libft/includes/libft.h"
#include <sys/sysctl.h>
#include <pthread.h>

int		set_get_screen_lines_per_thread(int core_number, int which)
{
	static int lines_per_thread = 0;
	static int lines_per_small_thread = 0;

	if (!core_number)
	{
		if (which == BIG)
			return (lines_per_thread);
		else if (which == SMALL)
			return (lines_per_small_thread);
	}
	lines_per_thread = Y_SIZE / set_get_core_numbers();
	lines_per_small_thread = Y_SIZE / set_get_core_numbers() / 4;
	return (lines_per_thread);
}

int		set_get_core_numbers(void)
{
	static int		core_number = 0;
	static size_t	count_len = sizeof(core_number);

	if (!core_number)
		sysctlbyname("hw.logicalcpu", &core_number, &count_len, NULL, 0);
	return (core_number);
}
#include <stdio.h>
void	create_threads(void func(void*), void *arg)
{
	int				y;
	t_info			*info;
	pthread_t		threads[Y_SIZE];

	y = -1;
	info = arg;
	if ((*info).which == SMALL)
	{
		(*info).screen = &(*info).screen[X_SIZE - X_SIZE / 4];
		(*info).screen = &(*info).screen[(Y_SIZE - Y_SIZE / 4) * X_SIZE];
	}
	while (++y < set_get_core_numbers())
	{
		(*info).screen = &(*info).screen[y * X_SIZE * set_get_screen_lines_per_thread(0, (*info).which)];
		if (pthread_create(&threads[y], NULL, (void*)func,
			(void*)info))
			ft_myexit("thread creation error");
	}
	y = -1;
	while (++y < set_get_core_numbers())
		pthread_join(threads[y], NULL);
}

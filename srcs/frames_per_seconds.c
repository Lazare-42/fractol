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
		if (time_since -launchtime == 1)
		{
			ft_putnbr((int)(fps));
			ft_putstr(" FPS\n");
		}
		else
			ft_putstr("FPS < 1\n");
		if (!(time(&launchtime)))
			return ;
		fps = 0;
	}
	fps++;
}

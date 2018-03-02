#include <sys/time.h>
#include "../libft/includes/libft.h"

void	put_fps(void)
{
	time_t			launchtime;
	static int		difference = -1;
	static int		frames_per_seconds = 0;

	if (!(time(&launchtime)))
		return ;
	if (!difference)
		difference = launchtime;
	if (difference == launchtime)
		frames_per_seconds++;
	else
	{
		ft_putnbr(frames_per_seconds);
		ft_putstr(" FPS\n");
		difference = 0;
		frames_per_seconds = 0;
	}
}

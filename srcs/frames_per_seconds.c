#include <sys/time.h>
#include "../libft/includes/libft.h"

void	put_fps(void)
{
	time_t	launchtime = 0;
	static int		difference = 0;
	static int		frames_per_seconds = 0;

	time(&launchtime);
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

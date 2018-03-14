#include "../includes/fractol.h"
#include <sys/sysctl.h>

int		set_get_screen_lines_per_thread(int core_number)
{
	static int lines_per_thread = 0;

	if (!core_number)
		return (lines_per_thread);
	else
		lines_per_thread = Y_SIZE / set_get_core_numbers();
	return (lines_per_thread);
}

int		set_get_core_numbers(void)
{
	static int core_number = 0;
	static size_t count_len = sizeof(core_number);

	if (!core_number)
		sysctlbyname("hw.logicalcpu", &core_number, &count_len, NULL, 0);
	return (core_number);
}

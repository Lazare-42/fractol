#include "../includes/fractol.h"

t_complx	set_get_mouse_pos_at_zoom(int	set)
{
	static t_complx offset = {0, 0, 0};
	static t_complx mouse = {0, 0, 0};
	static double	zoom_before;
	static double   zoom_after;

	if (!set)
		return (offset);
	if (set < 0)
		zoom_before = set_get_focus(0) * 2;
	else
	{
		zoom_after = set_get_focus(0) * 2;
		if (set_get_mouse_pos(0, 0).i == mouse.i)
			set_get_mouse_pos((double)((double)(mouse.r / zoom_before) * zoom_after), (double)((double)(mouse.i / zoom_before) * zoom_after));
		mouse = set_get_mouse_pos(0, 0);
		offset.i = (double)((zoom_after - zoom_before) *
				(double)(mouse.i / zoom_before))  + offset.i;
		offset.r = (double)((zoom_after - zoom_before) *
				(double)(mouse.r / zoom_before))  + offset.r;
	}
	return (offset);
}

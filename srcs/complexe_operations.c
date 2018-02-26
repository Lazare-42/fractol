#include "../includes/fractol.h"

t_complx	multiply_complexes(t_complx a, t_complx b)
{
	t_complx result;

	result.r = a.r * b.r - a.i * b.i;
	result.i = a.r * b.i + b.r * b.i;
	return (result);
}

t_complx	add_complexes(t_complx a, t_complx b)
{
	t_complx result;

	result.r = a.r + b.r;
	result.i = a.i + b.i;
	return (result);
}

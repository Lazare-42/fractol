/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:54:32 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/25 19:15:08 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define X_SIZE 2432
# define Y_SIZE 1368

# define KEY_LEFT 1
# define KEY_RIGHT 3
# define KEY_DOWN 14
# define KEY_UP 2
# define ZOOM_IN 8
# define ZOOM_OUT 9
# define X_ROTATE_UP 126
# define X_ROTATE_DOWN 125
# define Y_ROTATE_UP 124
# define Y_ROTATE_DOWN 123
# define Z_ROTATE_UP 6
# define Z_ROTATE_DOWN 7
# define CAMERA_SETBACK 10932

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*image;
	int				*screen_data;
}					t_mlx;

typedef struct		s_complx
{
	double			r;
	double			i;
}					t_complx;

void		print_handler(double ***tabtab,
		int print, int **screen, int *dimensions);
double				***matrix_multiplication(double ***tab, int *dimensions);
double				***center_matrix(double ***tab, int *field_size);
double				*set_get_pixel(double *new_point);
double				set_get_zoom_x(int zoom);
double				set_get_zoom_y(int zoom);
void				zoom_handler(int input_operation);
int					location_handler(int input_operation);
double				***store_tab(double ***tabtab);
int					check_if_input(int input_operation);
void				put_screen_str(int **screen, int print);
void				square_fractal(int **screen, int print);
void				screen_fill(int **screen, int size,
		int start_location, int print);
int					set_get_color(int change);
void				mandelbrot(int **screen);

#endif

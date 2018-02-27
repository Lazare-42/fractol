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

# define X_SIZE 1920
# define Y_SIZE 1200

#define MAX_COLOR_DISTANCE 200

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
	int				keycode;
}					t_mlx;

typedef struct		s_complx
{
	double			r;
	double			i;
}					t_complx;

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
void				square_fractal(int **screen);
void			screen_fill(int **screen, int size, int start_location);
int					set_get_color(int change);
void				mandelbrot(int **screen);
t_complx			multiply_complexes(t_complx a, t_complx b);
t_complx	add_complexes(t_complx a, t_complx b);
void				julia(int **screen, t_complx complx_nbr_suite);
void				fractal_handler(void);
int					**set_get_screen_cursor(int **screen_position);
t_mlx				set_get_mlx(t_mlx *mlx);
t_complx			set_get_mouse_pos(double x, double y);
int					set_get_fractal_choosen(int fractal_number);
double				set_get_focus(int sign);
int					pause_julia(int activate);

#endif

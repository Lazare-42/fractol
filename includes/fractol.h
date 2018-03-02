/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:21:32 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/27 11:25:05 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define X_SIZE 1920
# define Y_SIZE 1200

# define MAX_COLOR_DISTANCE 200

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
	double			pos_offset;
}					t_complx;

typedef struct		s_screen_line
{
	t_complx		complx_nbr;
	t_complx		complx_nbr_suite;
	int				y;
	int				x;
	int				**screen;
	double			increment_r;
}					t_screen_line;		

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
void				screen_fill(int **screen, int size, int start_location);
int					set_get_color(int change);
void				fractal(int **screen, t_complx complx_nbr_suite);
void				fractal_handler(void);
int					**set_get_screen_cursor(int **screen_position);
t_mlx				set_get_mlx(t_mlx *mlx);
t_complx			set_get_mouse_pos(double x, double y);
int					set_get_fractal_choosen(int fractal_number);
double				set_get_focus(int sign);
int					pause_julia(int activate);
double				get_fractal_focus(void);
double				color_range(double color);
int					mouse_zoom(int button, int x, int y, int b);
int					mouse_func(int x, int y, int b);
int					mouse_zoom(int button, int x, int y, int b);
int					keycode_func(int keycode, int b);
int					loop_fractal(int necessary);
void				put_fps(void);
//pthread_t			**create_threads(void);

#endif

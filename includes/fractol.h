/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:47:10 by lazrossi          #+#    #+#             */
/*   Updated: 2018/08/26 17:12:58 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define X_SIZE 1440
# define Y_SIZE 1200
# define KEYPRESS 2
# define KEYRELEASE 3
# define BUTTONPRESS 4
# define BUTTONRELEASE 5
# define MOTIONNOTIFY 6
# define ENTERNOTIFY 7
# define LEAVENOTIFY 8
# define FOCUSIN 9
# define ZOOM_IN 0.95
# define ZOOM_OUT 1.05
# define INIT_COLOR_DISTANCE 60
# define SPACE_BAR 49
# define ESC 53
# define PLUS 69
# define P 35
# define MINUS 78
# define M 46
# define VIOLET 0x9370DB
# define CYAN	0x37FDFC
# define GREY	0xA9A9A9
# define P_RED    0xFF6961
# define WIN_CO 0xee0000
# define JULIA 5
# define BUDHA  9
# define MANDELBROT 12
# define SQUARE 6
# define FRACTAL 10
# define ERROR -1235678
# define BIG 2048
# define SMALL 1024

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*image;
	int				*screen_data;
	int				keycode;
}					t_mlx;

typedef struct		s_location
{
	double			x;
	double			y;
}					t_location;

typedef struct		s_complx
{
	double			r;
	double			i;
	double			pos_offset;
}					t_complx;

typedef struct		s_screen_line
{
	t_complx		complx_nbr;
	double			increment_r;
	double			offset_x;
	double			offset_y;
}					t_screen_line;

typedef struct		s_info
{
	int				**screen;
	int				which;
	double			increment_r;
	t_screen_line	line[Y_SIZE];
	t_complx		complx_nbr_suite;
}					t_info;

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
void				screen_fill(int **screen, int size, int start_location,
		int sqrt);
double				square_color_range(int square_center);
void				fractal(t_info info);
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
int					put_fps(void);
t_complx			multiply_complexes(t_complx a, t_complx b);
t_complx			add_complexes(t_complx a, t_complx b);
t_complx			set_get_mouse_pos_at_zoom(int set);
int					set_get_core_numbers(void);
int					set_get_screen_lines_per_thread(int core_number, int which);
int					set_get_max_color_distance(int max_color_scale);
void				budhabrot(int **screen, t_complx complx_nbr_suite);
int					set_get_max_color_scale(int max_color_scale);
void				create_threads(void func(void*), void *arg);
int					set_get_iterations(int action);

#endif

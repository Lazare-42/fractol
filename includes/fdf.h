/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:54:32 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/22 12:20:53 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define X_SIZE 2560
# define Y_SIZE 1440

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

double				***ft_parsing(char *arg, int **dimensions);
void				print_tab_debug(double ***tabtab);
double				***camera_move(double ***tab, int input_operation,
		double **cos_sinus);
double				***create_rotation_matrix(double ***g_rotate_matrix);
double				***table_transform_handler(double ***tab, int input_op);
double				***first_camera_move(double ***tab, double **cos_sinus,
		int *camera_setback);
void				print_handler(double ***tab, int print,
		int **screen, int *dimensions);
double				***scale(double ***tab, int max_x, int max_y, int max_z);
double				***matrix_multiplication(double ***tab, int *dimensions);
double				***create_temp_tab(int	*dimensions, double ***tocopy);
double				***center_matrix(double ***tab, int *field_size);
int					redraw(int keycode, int *dimensions);
double				*set_get_cos_sinus(double *new_cos_sinus);
double				*set_get_radiuses(double *new_radiuses);
double				*set_get_pixel(double *new_point);
double				set_get_zoom_x(int zoom);
double				set_get_zoom_y(int zoom);
void				zoom_handler(int input_operation);
int					location_handler(int input_operation);
double				***store_tab(double ***tabtab);
int					check_if_input(int input_operation);
void				put_screen_str(int **screen, int print);
void				draw_line(double *from, double *to, int **scren, int print);

#endif

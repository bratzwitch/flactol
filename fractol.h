/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:21:00 by vmoroz            #+#    #+#             */
/*   Updated: 2024/09/19 15:34:06 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./lib_ft/includes/libft.h"
# include "./minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800

# define COLOR_PALETTE_SIZE 256
# define XK_Escape 69

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		fractal_type;
	int		color_palette[COLOR_PALETTE_SIZE];
	double	julia_re;
	double	julia_im;
	double	mouse_x;
	double	mouse_y;
	double	zoom;
}			t_data;

int			parse_arguments(int argc, char **argv, t_data *data);
int			close_win(int keycode, t_data *data);
void	initialize_color_palette(t_data *data);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			mandelbrot(double x, double y, int max_iter);
int			julia(double x, double y, int max_iter, double c_re, double c_im);
int			get_color(int iter, int max_iter, t_data *data);
int			render_next_frame(t_data *data);
int			mouse_move(int x, int y, t_data *data);
int			mouse_wheel(int button, int x, int y, t_data *data);

#endif
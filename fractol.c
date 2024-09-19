/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:23:08 by vmoroz            #+#    #+#             */
/*   Updated: 2024/09/19 14:57:45 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <X11/Xlib.h>
#include <math.h>
#include <unistd.h>

int	parse_arguments(int argc, char **argv, t_data *data)
{
	if (argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		data->fractal_type = 0;
	}
	else if (argc == 4 && ft_strcmp(argv[1], "julia") == 0)
	{
		data->fractal_type = 1;
		data->julia_re = ft_atof(argv[2]);
		data->julia_im = ft_atof(argv[3]);
	}
	else
	{
		ft_printf("%s", "Usage: %s [mandelbrot] or [julia <re> <im>]\n",
			argv[0]);
		return (1);
	}
	return (0);
}

void	cleanup(t_data *data)
{
	if (data == NULL)
		return ;
	if (data->img)
	{
		mlx_destroy_image(data->mlx, data->img);
		data->img = NULL;
	}
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
}

int	close_win(int keycode, t_data *data)
{
	(void)keycode;
	if (data)
	{
		cleanup(data);
	}
	exit(0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == 65307) // Escape key
	{
		cleanup(data);
		exit(0);
	}
	printf("Keypress: %d\n", keysym);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	julia(double x, double y, int max_iter, double c_re, double c_im)
{
	double	zx;
	double	zy;
	int		iter;
	double	temp;

	temp = 0;
	zx = x;
	zy = y;
	iter = 0;
	while (zx * zx + zy * zy < 4 && iter < max_iter)
	{
		temp = zx * zx - zy * zy + c_re;
		zy = 2 * zx * zy + c_im;
		zx = temp;
		iter++;
	}
	return (iter);
}

int	mandelbrot(double x, double y, int max_iter)
{
	double	zx;
	double	zy;
	int		iter;
	double	temp;

	temp = 0;
	zx = 0;
	zy = 0;
	iter = 0;
	while (zx * zx + zy * zy < 4 && iter < max_iter)
	{
		temp = zx * zx - zy * zy + x;
		zy = 2 * zx * zy + y;
		zx = temp;
		iter++;
	}
	return (iter);
}

int	get_color(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iter / max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

int	render_next_frame(t_data *data)
{
	double	move_x;
	double	move_y;
	int		max_iter;
	int		iter;
	int		color;
	int		x;
	int		y;
	double	uv_x;
	double	uv_y;
	double	c_x;
	double	c_y;

	iter = 0;
	color = 0;
	x = 0;
	y = 0;
	uv_x = 0;
	uv_y = 0;
	c_x = 0;
	c_y = 0;
	move_x = -0.69955;
	move_y = 0.37999;
	max_iter = 45;
	ft_memset(data->addr, 0, WIDTH * HEIGHT * (data->bits_per_pixel / 8));
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			uv_x = (x - 0.5 * WIDTH) / HEIGHT;
			uv_y = (y - 0.5 * HEIGHT) / HEIGHT;
			if (data->fractal_type == 0)
			{
				c_x = uv_x * data->zoom * 3. + move_x;
				c_y = uv_y * data->zoom * 3. + move_y;
				iter = mandelbrot(c_x, c_y, max_iter);
			}
			else
			{
				c_x = uv_x * data->zoom * 3.;
				c_y = uv_y * data->zoom * 3.;
				iter = julia(c_x, c_y, max_iter, data->julia_re,
					data->julia_im);
			}
			color = get_color(iter, max_iter);
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int	mouse_move(int x, int y, t_data *data)
{
	if (data->fractal_type == 1)
	{
		data->julia_re = (x / (double)WIDTH) * 4.0 - 2.0;
		data->julia_im = (y / (double)HEIGHT) * 4.0 - 2.0;
		mlx_clear_window(data->mlx, data->win);
		render_next_frame(data);
	}
	return (0);
}

int	mouse_wheel(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		data->zoom /= 1.08;
	}
	else if (button == 5)
	{
		data->zoom *= 1.08;
	}
	return (0);
}

void	exit_program(t_data *data)
{
	cleanup(data);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	img;

	if (parse_arguments(argc, argv, &img) != 0)
		return (1);
	img.mlx = mlx_init();
	if (!img.mlx)
	{
		cleanup(&img);
		return (1);
	}
	img.win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "Fractol");
	if (!img.win)
	{
		cleanup(&img);
		return (1);
	}
	img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
	if (!img.img)
	{
		cleanup(&img);
		return (1);
	}
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		&img.endian);
	if (!img.addr)
	{
		cleanup(&img);
		return (1);
	}
	img.mouse_x = 0.5;
	img.mouse_y = 0.5;
	img.zoom = 1.0;
	mlx_loop_hook(img.mlx, render_next_frame, &img);
	mlx_mouse_hook(img.win, mouse_wheel, &img);
	mlx_hook(img.win, 6, 1L << 6, mouse_move, &img);
	mlx_hook(img.win, DestroyNotify, NoEventMask, (int (*)(void *))exit_program,
		&img);
	mlx_hook(img.win, KeyPress, KeyPressMask, handle_keypress, &img);
	mlx_loop(img.mlx);
	return (0);
}

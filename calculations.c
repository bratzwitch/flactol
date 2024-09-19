/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:48:58 by vmoroz            #+#    #+#             */
/*   Updated: 2024/09/19 18:00:07 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_complex(t_data *data, double uv_x, double uv_y, double *c)
{
	if (data->fractal_type == 0)
	{
		c[0] = uv_x * data->zoom * 3.0 - 0.69955;
		c[1] = uv_y * data->zoom * 3.0 + 0.37999;
	}
	else
	{
		c[0] = -uv_x * data->zoom * 3.0;
		c[1] = uv_y * data->zoom * 3.0;
	}
}

int	calculate_iterations(t_data *data, double c_x, double c_y, int max_iter)
{
	if (data->fractal_type == 0)
	{
		return (mandelbrot(c_x, c_y, max_iter));
	}
	else
	{
		return (julia(c_x, c_y, max_iter, data->julia_re, data->julia_im));
	}
}

void	render_pixel(t_data *data, int x, int y, int max_iter)
{
	double	uv_x;
	double	uv_y;
	int		iter;
	double	c[2];

	c[0] = 0;
	c[1] = 0;
	uv_x = (x - 0.5 * WIDTH) / HEIGHT;
	uv_y = (y - 0.5 * HEIGHT) / HEIGHT;
	calculate_complex(data, uv_x, uv_y, c);
	iter = calculate_iterations(data, c[0], c[1], max_iter);
	my_mlx_pixel_put(data, x, y, get_color(iter, max_iter, data));
}

int	render_next_frame(t_data *data)
{
	int	max_iter;
	int	x;
	int	y;

	max_iter = 100;
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			render_pixel(data, x, y, max_iter);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numparseclean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:44:32 by vmoroz            #+#    #+#             */
/*   Updated: 2024/09/19 18:20:23 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_number(const char *str)
{
	int	has_decimal;
	int	has_digits;

	if (*str == '\0')
		return (0);
	has_decimal = 0;
	has_digits = 0;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (ft_isdigit(*str))
			has_digits = 1;
		else if (*str == '.' && !has_decimal)
			has_decimal = 1;
		else
			return (0);
		str++;
	}
	return (has_digits);
}

int	parse_arguments(int argc, char **argv, t_data *data)
{
	t_data img;

	img.mouse_x = 0.5;
	img.mouse_y = 0.5;
	img.zoom = 1.0;
	if (argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		data->fractal_type = 0;
	}
	else if (argc == 4 && ft_strcmp(argv[1], "julia") == 0)
	{
		if (!is_number(argv[2]) || !is_number(argv[3]))
		{
			ft_printf("%s", "Error: Julia arguments must be valid numbers.\n");
			return (1);
		}
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

void	initialize_color_palette(t_data *data)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	while (i < COLOR_PALETTE_SIZE)
	{
		r = (i % 8) * 32;
		g = (i % 16) * 16;
		b = (i % 32) * 8;
		data->color_palette[i] = (r << 16) | (g << 8) | b;
		i++;
	}
}

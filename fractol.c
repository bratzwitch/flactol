/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:23:08 by vmoroz            #+#    #+#             */
/*   Updated: 2024/09/19 18:20:51 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	exit_program(t_data *data)
{
	cleanup(data);
	exit(0);
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
	if (keysym == 65307)
	{
		cleanup(data);
		exit(0);
	}
	printf("Keypress: %d\n", keysym);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	img;

	if (parse_arguments(argc, argv, &img) != 0)
		return (1);
	initialize_color_palette(&img);
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "Fractol");
	img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	if (!img.mlx || !img.win || !img.img || !img.addr)
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

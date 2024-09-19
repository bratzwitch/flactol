/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   somehooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:50:13 by vmoroz            #+#    #+#             */
/*   Updated: 2024/09/19 18:19:19 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	mouse_move(int x, int y, t_data *data)
{
	if (data->fractal_type == 1)
	{
		data->julia_re = (x / (double)WIDTH) * 4.0 - 2.0;
		data->julia_im = (y / (double)HEIGHT) * 4.0 - 2.0;
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

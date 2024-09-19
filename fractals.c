/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:47:30 by vmoroz            #+#    #+#             */
/*   Updated: 2024/09/19 17:47:54 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

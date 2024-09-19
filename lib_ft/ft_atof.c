/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:26:24 by vmoroz            #+#    #+#             */
/*   Updated: 2024/09/19 17:57:19 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_atof(char *str)
{
	double	result;
	double	factor;
	int		sign;

	result = 0.0;
	factor = 1.0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			result += (*str - '0') / (factor *= 10.0);
			str++;
		}
	}
	return (result * sign);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_udecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:03:00 by vmoroz            #+#    #+#             */
/*   Updated: 2024/02/17 14:15:52 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	num_len(unsigned int num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		i++;
		num = num / 10;
	}
	return (i);
}

char	*ft_uitoa(unsigned int num)
{
	char	*result;
	int		i;

	i = num_len(num);
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (!result)
		return (0);
	result[i] = '\0';
	while (num != 0)
	{
		result[i - 1] = num % 10 + 48;
		num = num / 10;
		i--;
	}
	return (result);
}

int	ft_udecimal(unsigned int num)
{
	int		result;
	char	*str;

	result = 0;
	if (num == 0)
		result += write(1, "0", 1);
	else
	{
		str = ft_uitoa(num);
		result += ft_printstr(str);
		free(str);
	}
	return (result);
}

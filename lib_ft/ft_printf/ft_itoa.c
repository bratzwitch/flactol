/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:50:01 by vmoroz            #+#    #+#             */
/*   Updated: 2024/02/17 14:15:23 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	digits_num(int n)
{
	int	num;

	num = 1;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		num++;
	}
	return (num);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*underflow(void)
{
	char	*str;

	str = (char *)malloc(12);
	if (!str)
	{
		return (NULL);
	}
	ft_strcpy(str, "-2147483648");
	return (str);
}

char	convert_num(int total, int ind, char *res, int num)
{
	while (total > 0)
	{
		ind--;
		res[ind] = '0' + (num % 10);
		num /= 10;
		total--;
	}
	return (*res);
}

char	*ft_itoa(int n)
{
	int		total_num;
	int		sign;
	char	*result;
	int		index;

	total_num = digits_num(n);
	sign = 0;
	if (n == -2147483648)
		return (underflow());
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	result = (char *)malloc(total_num + sign + 1);
	if (!result)
		return (NULL);
	index = total_num + sign;
	result[index] = '\0';
	convert_num(total_num, index, result, n);
	if (sign == 1)
		result[0] = '-';
	return (result);
}

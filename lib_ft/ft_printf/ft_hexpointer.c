/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:58:54 by vmoroz            #+#    #+#             */
/*   Updated: 2024/02/17 14:15:14 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ptr_len(uintptr_t num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		i++;
		num = num / 16;
	}
	return (i);
}

void	put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		put_ptr(num / 16);
		put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_hexpointer(unsigned long long ptr)
{
	int	result;

	result = 0;
	if (ptr == 0)
	{
		result += ft_printstr("(nil)");
	}
	else
	{
		result += ft_printstr("0x");
		put_ptr(ptr);
		result += ptr_len(ptr);
	}
	return (result);
}

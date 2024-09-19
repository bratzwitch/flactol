/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:25:34 by vmoroz            #+#    #+#             */
/*   Updated: 2024/02/12 15:48:11 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memset(void *dest, int value, size_t count)
{
	unsigned char	*byte_dest;
	unsigned char	byte_value;

	byte_dest = (unsigned char *)dest;
	byte_value = (unsigned char)value;
	while (count--)
	{
		*byte_dest = byte_value;
		byte_dest++;
	}
	return (dest);
}
// int	main(void)
// {
// 	char str[] = "5";
// 	printf("%s\n", str);
// 	ft_memset(str, 'f', sizeof(str) - 1);
// 	printf("%s\n", str);
// 	return (0);
// }
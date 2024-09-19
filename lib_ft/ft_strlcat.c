/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:26:52 by vmoroz            #+#    #+#             */
/*   Updated: 2024/02/12 15:48:11 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (!dest && size == 0)
		return (ft_strlen(src));
	i = ft_strlen(dest);
	j = 0;
	if (i >= size)
		return (ft_strlen(src) + size);
	while (i + j < size - 1 && src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (i + ft_strlen(src));
}

// int	main(void)
// {
// 	char str1[100] = "HI ";
// 	char str2[100] = "dude, whats up";

// 	int a = ft_strlcat(str1, str2, 5);

// 	printf("Concatenated string: %s\n size %i", str1, a);

// 	return (0);
// }
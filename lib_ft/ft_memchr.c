/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:26:22 by vmoroz            #+#    #+#             */
/*   Updated: 2024/02/12 15:48:11 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memchr(const void *src, int chr, size_t n)
{
	size_t	i;
	char	*to_find;

	i = 0;
	to_find = (char *)src;
	while (i < n)
	{
		if (to_find[i] == (char)chr)
			return (to_find + i);
		i++;
	}
	return (NULL);
}
// int	main(void)
// {
// 	char str[] = "geeesgooo";
// 	char *ptr = ft_memchr(str, 's', 6);
// 	if (ptr != NULL)
// 	{
// 		printf("'s' found at pos %ld.\n", ptr - str + 1);
// 		printf("char found: %s\n", ptr);
// 	}
// 	else
// 	{
// 		printf("char not found\n");
// 	}
// 	return (0);
// }
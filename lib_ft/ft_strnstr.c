/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:27:20 by vmoroz            #+#    #+#             */
/*   Updated: 2024/02/12 15:48:11 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*str2)
		return ((char *)str1);
	while (i < len && str1[i] != '\0')
	{
		if (str1[i] == str2[0])
		{
			while (str2[j] != '\0' && str1[i + j] == str2[j] && i + j < len)
			{
				if (str2[j + 1] == '\0')
					return ((char *)&str1[i]);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
// int	main(void)
// {
// 	const char	*str1;
// 	const char	*str2;
// 	char		*result;

// 	str1 = "Hello, world world";
// 	str2 = "world world";
// 	result = ft_strnstr(str1, str2, 20);
// 	if (result)
// 		printf("Found: %s\n", result);
// 	else
// 		printf("Not found\n");
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:26:31 by vmoroz            #+#    #+#             */
/*   Updated: 2024/02/12 15:48:11 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_memcmp(void *str1, void *str2, int l)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = str1;
	s2 = str2;
	while (l > 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		l--;
		s1++;
		s2++;
	}
	return (0);
}
// int	main(void)
// {
// 	char *str;
// 	char *str2;
// 	int i;

// 	str = strdup("hello");
// 	str2 = strdup("helloa");
// 	i = ft_memcmp(str, str2, 6);
// 	printf("%d\n", i);
// }
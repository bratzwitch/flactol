/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:27:15 by vmoroz            #+#    #+#             */
/*   Updated: 2024/02/12 15:48:11 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strrchr(const char *str, int chr)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	while (i >= 0)
	{
		if (str[i] == (char)chr)
			return ((char *)(str + i));
		i--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char *s = "dsfclsds";
// 	char want_search = 'l';
// 	char *ptr = ft_strrchr(s, want_search);
// 	if (ptr != NULL)
// 	{
// 		printf("Last occurence of 'l' found at %ld.\n", ptr - s + 1);
// 		printf("search character found:  %s\n", ptr);
// 	}
// 	else
// 	{
// 		printf("search character not found\n");
// 	}
// 	return (0);
// }

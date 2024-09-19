/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:47:15 by vmoroz            #+#    #+#             */
/*   Updated: 2024/02/12 15:48:11 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)ch)
			return ((char *)str + i);
		i++;
	}
	if (ch == 0)
		return ((char *)str + (ft_strlen(str)));
	return (NULL);
}
// int	main(void)
// {
// 	char s[] = "abcbc";
// 	ft_strchr(s, 'b');
// 	ft_strchr(s, 'c');
// 	ft_strchr(s, 'd');
// 	printf("this should return (%s\n", ft_strchr(s, 'c')));
// 	return (0);
// }
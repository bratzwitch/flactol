/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:27:26 by vmoroz            #+#    #+#             */
/*   Updated: 2024/02/12 15:48:11 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && *s1 && (*s1 == *s2))
	{
		++s1;
		++s2;
		--n;
	}
	if (n == 0)
	{
		return (0);
	}
	else
	{
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	}
}

// int	main(void)
// {
// 	char *s1;
// 	char *s2;
// 	int result;

// 	s1 = "dahd1";
// 	s2 = "dahda";
// 	result = ft_strncmp(s1, s2, 15);
// 	if (result == 0)
// 	{
// 		printf("The strings are equal\n");
// 	}
// 	else if (result < 0)
// 	{
// 		printf("s1 is less than s2\n");
// 	}
// 	else
// 	{
// 		printf("s1 is greater than s2\n");
// 	}
// 	return (0);
// }
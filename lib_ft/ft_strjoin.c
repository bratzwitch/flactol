/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:21:43 by vmoroz            #+#    #+#             */
/*   Updated: 2024/02/12 15:48:11 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static char	*ft_strcpy(char *dest, const char *src)
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

static char	*ft_strcat(char *dest, const char *src)
{
	int	ld;
	int	ls;

	ld = 0;
	while (dest[ld] != '\0')
	{
		ld++;
	}
	ls = 0;
	while (src[ls] != '\0')
	{
		dest[ld] = src[ls];
		ld++;
		ls++;
	}
	dest[ld] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	ft_strcpy(result, s1);
	ft_strcat(result, s2);
	return (result);
}

// int main(void) {
//     const char *s1 = "Hello, ";
//     const char *s2 = "world!";

//     char *result = ft_strjoin(s1, s2);

//     if (result) {
//         printf("Concatenated string: %s\n", result);
//         free(result);
//     } else {
//         printf("Memory allocation failed.\n");
//     }

//     return (0);
// }

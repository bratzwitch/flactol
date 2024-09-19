/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:26:50 by vmoroz            #+#    #+#             */
/*   Updated: 2024/02/12 15:48:11 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*end;
	size_t		len;
	char		*result;
	char		*ptr;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && is_in_set(*s1, set))
		s1++;
	end = s1;
	while (*end)
		end++;
	while (end > s1 && is_in_set(*(end - 1), set))
		end--;
	len = end - s1;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	ptr = result;
	while (len--)
	{
		*ptr++ = *s1++;
	}
	*ptr = '\0';
	return (result);
}

// int	main(void)
// {
// 	const char *s1 = "   \t  obrezanie\n  ";
// 	const char *set = " \t zanie \n";
// 	char *trimmed = ft_strtrim(s1, set);

// 	if (trimmed != NULL)
// 	{
// 		printf("Original: \"%s\"\n", s1);
// 		printf("Trimmed: \"%s\"\n", trimmed);
// 		free(trimmed);
// 	}
// 	else
// 	{
// 		printf("Memory allocation failed or input was invalid.\n");
// 	}

// 	return (0);
// }
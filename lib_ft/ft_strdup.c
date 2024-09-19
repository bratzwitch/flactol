/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:26:46 by vmoroz            #+#    #+#             */
/*   Updated: 2024/02/12 15:48:11 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strdup(char *src)
{
	char	*str;
	char	*p;
	int		len;

	len = 0;
	while (src[len])
		len++;
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	p = str;
	while (*src)
		*str++ = *src++;
	*str = '\0';
	return (p);
}
// int	main(void)
// {
// 	char original[12] = "Sheeesh chel";
// 	char *duplicate;
// 	int o_len;
// 	int d_len;

// 	duplicate = ft_strdup(original);
// 	o_len = strlen(original);
// 	d_len = strlen(duplicate);

// 	printf("Original String: '%s' (%d)\n", original, o_len);
// 	printf("Duplicate string: '%s' (%d)\n", duplicate, d_len);

// 	return (0);
// }
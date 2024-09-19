/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:22:33 by vmoroz            #+#    #+#             */
/*   Updated: 2024/02/12 15:48:11 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}

// int	main(void)
// {
// 	char	str1[] = "abcdasva";
//     ft_striteri(str1,prev_ascii);
// 	printf("%s\n", str1);
//     return (0);
// }
// void next_alpha(unsigned int i, char *c)
// {
//     if(c[i] >= 0 && c[i] <= 127)
//     {
//         if (c[i] == 127) {
//             c[i] = 0;
//         } else {
//             (*c)++;
//         }
//     }
// }
// void prev_ascii(unsigned int i, char *c)
// {
//     if(c[i] >= 0 && c[i] <= 127)
//     {
//         if (c[i] == 127) {
//             c[i] = 0;
//         } else {
//             (*c)--;
//         }
//     }
// }
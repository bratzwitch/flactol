/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:26:10 by vmoroz            #+#    #+#             */
/*   Updated: 2024/02/12 15:48:11 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*msrc;
	unsigned char	*mdest;
	int				i;

	i = 0;
	msrc = (unsigned char *)src;
	mdest = (unsigned char *)dest;
	if (mdest == NULL && msrc == NULL)
	{
		return (0);
	}
	while (n != 0)
	{
		mdest[i] = msrc[i];
		i++;
		n--;
	}
	return (mdest);
}
// int	main(void)
// {
// 	char src[] = "hey man whats up";
// 	char dest[20];
// 	ft_memcpy(dest, src, sizeof(src));
// 	printf("dest = %s\n", dest);
// 	return (0);
// }
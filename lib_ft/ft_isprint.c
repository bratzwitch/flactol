/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:47:49 by vmoroz            #+#    #+#             */
/*   Updated: 2024/02/12 15:48:11 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (c);
	return (0);
}
// int	main(void)
// {
// 	char input1[] = "Hello123";
// 	char input2[] = "\n";
// 	char input3[] = "123456";
// 	char input4[] = "!@#";

// 	if (ft_isprint(input1))
// 	{
// 		printf("\"%s\" contains only print characters.\n", input1);
// 	}
// 	else
// 	{
// 		printf("\"%s\" contains non-print characters.\n", input1);
// 	}

// 	if (ft_isprint(input2))
// 	{
// 		printf("\"%s\" contains only print characters.\n", input2);
// 	}
// 	else
// 	{
// 		printf("\"%s\" contains non-print characters.\n", input2);
// 	}

// 	if (ft_isprint(input3))
// 	{
// 		printf("\"%s\" contains only print characters.\n", input3);
// 	}
// 	else
// 	{
// 		printf("\"%s\" contains non-print characters.\n", input3);
// 	}

// 	if (ft_isprint(input4))
// 	{
// 		printf("\"%s\" contains only print characters.\n", input4);
// 	}
// 	else
// 	{
// 		printf("\"%s\" contains non-print characters.\n", input4);
// 	}

// 	return (0);
// }
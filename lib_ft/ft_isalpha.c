/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:47:32 by vmoroz            #+#    #+#             */
/*   Updated: 2024/02/12 15:48:11 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (c);
	return (0);
}
// int	main(void)
// {
// 	char input1[] = "Hello123";
// 	char input2[] = "AbCdEf";
// 	char input3[] = "123456";
// 	char input4[] = "!@#";

// 	if (ft_isalpha(input1))
// 	{
// 		printf("\"%s\" contains only alphabet characters.\n", input1);
// 	}
// 	else
// 	{
// 		printf("\"%s\" contains non-alphabet characters.\n", input1);
// 	}

// 	if (ft_isalpha(input2))
// 	{
// 		printf("\"%s\" contains only alphabet characters.\n", input2);
// 	}
// 	else
// 	{
// 		printf("\"%s\" contains non-alphabet characters.\n", input2);
// 	}

// 	if (ft_isalpha(input3))
// 	{
// 		printf("\"%s\" contains only alphabet characters.\n", input3);
// 	}
// 	else
// 	{
// 		printf("\"%s\" contains non-alphabet characters.\n", input3);
// 	}

// 	if (ft_isalpha(input4))
// 	{
// 		printf("\"%s\" contains only alphabet characters.\n", input4);
// 	}
// 	else
// 	{
// 		printf("\"%s\" contains non-alphabet characters.\n", input4);
// 	}

// 	return (0);
// }
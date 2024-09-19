/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:06:45 by vmoroz            #+#    #+#             */
/*   Updated: 2024/02/12 15:48:11 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

// int main() {
//     // Create a new t_list node with some content
//     int data = 10;
//     t_list *node = ft_lstnew(&data);

//     // Check if the node was created successfully
//     if (node) {
//         printf("Node created successfully.\n");
//         printf("Content: %d\n", *(int *)(node->content));

//         // Don't forget to free the memory allocated for the node
//         free(node);
//     } else {
//         printf("Failed to create a new node.\n");
//     }

//     return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:19:37 by vmoroz            #+#    #+#             */
/*   Updated: 2024/02/12 15:48:11 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
	{
		return (NULL);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

// int main() {
//     // Create a linked list
//     struct Node* head = NULL; // Initialize an empty list

//     // Add nodes to the list (for demonstration)
//     // You can add nodes to the list as needed
//     // ...

//     // Call the function to find the last node
//     struct Node* lastNode = findLastNode(head);

//     // Check if the last node was found
//     if (lastNode != NULL) {
//         printf("The last node contains data: %d\n", lastNode->data);
//     } else {
//         printf("The list is empty.\n");
//     }

//     return 0;
// }

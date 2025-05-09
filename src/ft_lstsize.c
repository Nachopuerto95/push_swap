/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuerto- <jpuerto-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:40:16 by jpuerto-          #+#    #+#             */
/*   Updated: 2025/02/13 13:30:39 by jpuerto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/// @brief Return the size of a list
int	ft_lstsize(t_stack_node *stack)
{
	int	count;

	if (NULL == stack)
		return (0);
	count = 0;
	while (stack)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}
// int main() {
//     t_list *list = ft_lstnew("1");
//     t_list *node2 = ft_lstnew("2");
//     t_list *node3 = ft_lstnew("3");
//     list->next = node2;
//     node2->next = node3;

//     int size = ft_lstsize(list);

//     printf("SIze: %d\n", size);

//     free(list);
//     free(node2);
//     free(node3);

//     return 0;
// }

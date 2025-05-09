/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuerto- <jpuerto-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:38:00 by jpuerto-          #+#    #+#             */
/*   Updated: 2025/02/22 14:48:57 by jpuerto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = ft_lstlast(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (print)
		write(1, "rr\n", 3);
}

void	rotate_ab(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rr(a, b, true);
	get_index(*a);
	get_index(*b);
}

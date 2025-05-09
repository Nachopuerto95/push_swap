/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuerto- <jpuerto-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:13:07 by jpuerto-          #+#    #+#             */
/*   Updated: 2025/02/22 14:52:44 by jpuerto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	get_index(t_stack_node *stack)
{
	int	i;
	int	middle;

	i = 0;
	if (NULL == stack)
		return ;
	middle = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= middle)
			stack->above_mid = true;
		else
			stack->above_mid = false;
		stack = stack->next;
		++i;
	}
}

bool	is_ordered(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*b);
	if (cheapest_node->above_mid && cheapest_node->target->above_mid)
		rotate_ab(a, b, cheapest_node);
	else if (!(cheapest_node->above_mid)
		&& !(cheapest_node->target->above_mid))
		rev_rotate_ab(a, b, cheapest_node);
	prepare_push(b, cheapest_node, 'b');
	prepare_push(a, cheapest_node->target, 'a');
	pa(a, b, true);
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*min;
	int				len;

	min = find_min(*a);
	len = ft_lstsize(*a);
	while (len-- > 3)
		pb(b, a, true);
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_nodes(a, b);
	}
	get_index(*a);
	while ((*a)->value != min->value)
	{
		if (min->above_mid)
			ra(a, true);
		else
			rra(a, true);
	}
}

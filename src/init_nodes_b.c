/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuerto- <jpuerto-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:02:07 by jpuerto-          #+#    #+#             */
/*   Updated: 2025/02/19 18:12:19 by jpuerto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	get_target(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*target_node;
	t_stack_node	*current_a;
	long			best;

	while (b)
	{
		best = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best)
			{
				best = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best)
			b->target = find_min(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	get_price(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	while (b)
	{
		b->push_cost = b->index;
		if (!(b->above_mid))
			b->push_cost = len_b - (b->index);
		if (b->target->above_mid)
			b->push_cost += b->target->index;
		else
			b->push_cost += len_a - (b->target->index);
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *b)
{
	long			best_match_value;
	t_stack_node	*best_match_node;

	if (NULL == b)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->push_cost < best_match_value)
		{
			best_match_value = b->push_cost;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = true;
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	get_index(a);
	get_index(b);
	get_target(a, b);
	get_price(a, b);
	set_cheapest(b);
}

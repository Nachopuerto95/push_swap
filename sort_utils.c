/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuerto- <jpuerto-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:12:37 by jpuerto-          #+#    #+#             */
/*   Updated: 2025/02/22 14:53:40 by jpuerto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

t_stack_node	*find_max(t_stack_node *stack)
{
	t_stack_node	*aux;
	long			max_value;

	if (!stack)
		return (NULL);
	max_value = LONG_MIN;
	while (stack)
	{
		if (stack->value > max_value)
		{
			max_value = stack->value;
			aux = stack;
		}
		stack = stack->next;
	}
	return (aux);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	t_stack_node	*aux;
	long			min_value;

	if (!stack)
		return (NULL);
	min_value = LONG_MAX;
	while (stack)
	{
		if (stack->value < min_value)
		{
			min_value = stack->value;
			aux = stack;
		}
		stack = stack->next;
	}
	return (aux);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, true);
	else if ((*a)->next == biggest_node)
		rra(a, true);
	if ((*a)->value > (*a)->next->value)
		sa(a, true);
}

void	prepare_push(t_stack_node **stack, t_stack_node *top_node,
							char name)
{
	while (*stack != top_node)
	{
		if (name == 'a')
		{
			if (top_node->above_mid)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (name == 'b')
		{
			if (top_node->above_mid)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}

long	ft_atol(const char *str)
{
	long	num;
	int		i;
	int		is_negative;

	is_negative = 1;
	num = 0;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		is_negative *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * is_negative);
}

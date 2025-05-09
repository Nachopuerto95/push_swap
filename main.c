/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuerto- <jpuerto-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:13:07 by jpuerto-          #+#    #+#             */
/*   Updated: 2025/02/22 14:54:00 by jpuerto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node		*a;
	t_stack_node		*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	init_stack_a(&a, argv + 1);
	if (!is_ordered(a))
	{
		if (ft_lstsize(a) == 2)
			sa(&a, true);
		else if (ft_lstsize(a) == 3)
			sort_three(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
	return (0);
}

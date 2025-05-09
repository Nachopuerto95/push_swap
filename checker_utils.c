/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuerto- <jpuerto-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:11:07 by jpuerto-          #+#    #+#             */
/*   Updated: 2025/02/24 14:13:36 by jpuerto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

int	check_command(char *line, t_stack_node **a, t_stack_node **b)
{
	if (ft_strncmp(line, "pb\n", 3) == 0)
		return (pb(b, a, false), 1);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		return (rra(a, false), 1);
	else if (ft_strncmp(line, "pa\n", 2) == 0)
		return (pa(a, b, false), 1);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		return (ra(a, false), 1);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		return (rb(b, false), 1);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		return (rr(a, b, false), 1);
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		return (sa(a, false), 1);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		return (sb(a, false), 1);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		return (ss(a, b, false), 1);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		return (rrb(a, false), 1);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		return (rrr(a, b, false), 1);
	else
		return (0);
}

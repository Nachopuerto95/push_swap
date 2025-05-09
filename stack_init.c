/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuerto- <jpuerto-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:26:45 by jpuerto-          #+#    #+#             */
/*   Updated: 2025/02/20 18:39:04 by jpuerto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	check_repetition(t_stack_node *node, int nbr)
{
	if (node == NULL)
		return (1);
	while (node)
	{
		if (node->value == nbr)
			return (0);
		node = node->next;
	}
	return (1);
}

int	check_num(char	*nbr)
{
	if (!(*nbr == '+' || *nbr == '-' || (*nbr >= '0' && *nbr <= '9')))
		return (0);
	if ((*nbr == '+' || *nbr == '-') && !(nbr[1] >= '0' && nbr[1] <= '9'))
		return (0);
	while (*++nbr)
	{
		if (!(*nbr >= '0' && *nbr <= '9'))
			return (0);
	}
	return (1);
}

void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	node = malloc(sizeof(t_stack_node));
	if (!node || !stack)
		return ;
	node->value = n;
	node->next = NULL;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_lstlast(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	parse_args(char *argv, t_stack_node **a, char ***split)
{
	long	nbr;

	if (!argv || !check_num(argv))
	{
		if (split && *split)
			free_matrix(*split);
		throw_error(a, NULL, true);
	}
	nbr = ft_atol(argv);
	if (nbr > INT_MAX || nbr < INT_MIN || !check_repetition(*a, (int)nbr))
	{
		if (split && *split)
			free_matrix(*split);
		throw_error(a, NULL, true);
	}
	append_node(a, (int)nbr);
}

void	init_stack_a(t_stack_node **a, char **argv)
{
	int		i;
	int		j;
	char	**split;

	i = -1;
	while (argv[++i])
	{
		if (ft_strchr(argv[i], ' '))
		{
			split = ft_split(argv[i], ' ');
			if (!split || !split[0])
			{
				free(split);
				throw_error(a, NULL, true);
			}
			j = -1;
			while (split[++j])
			{
				parse_args(split[j], a, &split);
			}
			free_matrix(split);
		}
		else
			parse_args(argv[i], a, NULL);
	}
}

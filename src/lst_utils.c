/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuerto- <jpuerto-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:49:02 by jpuerto-          #+#    #+#             */
/*   Updated: 2025/02/11 11:07:20 by jpuerto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lstadd_back(t_stack_node **lst, int nbr)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (lst == NULL)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->value = nbr;
	if (*lst == NULL)
		*lst = new_node;
	else
	{
		last_node = ft_lstlast(*lst);
		last_node->next = new_node;
	}
}

t_stack_node	*ft_lstlast(t_stack_node *lst)
{
	if (!lst)
		return (0);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}

void	free_matrix(char **argv)
{
	int	i;

	i = 0;
	if (NULL == argv || NULL == *argv)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (NULL == stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

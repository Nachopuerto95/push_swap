/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuerto- <jpuerto-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:32:31 by jpuerto-          #+#    #+#             */
/*   Updated: 2025/02/20 20:11:01 by jpuerto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	throw_error(t_stack_node **a, char **matrix, bool do_exit)
{
	if (a)
		free_stack(a);
	if (matrix)
		free_matrix(matrix);
	write(2, "Error\n", 6);
	if (do_exit == true)
		exit(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuerto- <jpuerto-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:30:24 by jpuerto-          #+#    #+#             */
/*   Updated: 2025/02/24 14:13:21 by jpuerto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	do_command(char *line, t_stack_node **a, t_stack_node **b)
{
	if (!line)
		return (0);
	if (!check_command(line, a, b))
	{
		free(line);
		free_stack(b);
		throw_error(a, NULL, true);
	}
	return (1);
}

void	parse_args_bonus(char *argv, t_stack_node **a, char ***split)
{
	long	nbr;

	if (!argv || !check_num(argv))
	{
		if (split && *split)
			free_matrix(*split);
		throw_error(a, NULL, false);
	}
	nbr = ft_atol(argv);
	if (nbr > INT_MAX || nbr < INT_MIN || !check_repetition(*a, (int)nbr))
	{
		if (split && *split)
			free_matrix(*split);
		throw_error(a, NULL, false);
	}
	append_node(a, (int)nbr);
}

int	init_stack_bonus(t_stack_node **a, char **argv)
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
				return (free(split), throw_error(a, NULL, false), 0);
			j = -1;
			while (split[++j])
				parse_args(split[j], a, &split);
			free_matrix(split);
		}
		else
			parse_args(argv[i], a, NULL);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*line;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	init_stack_a(&a, argv + 1);
	while (!(is_ordered(a) && ft_lstsize(b) == 0))
	{
		line = get_next_line(0);
		if (!do_command(line, &a, &b))
		{
			free(line);
			break ;
		}
		free(line);
	}
	if (is_ordered(a) && ft_lstsize(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_stack(&a), free_stack(&b), 0);
}

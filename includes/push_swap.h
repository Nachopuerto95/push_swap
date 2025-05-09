/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuerto- <jpuerto-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:08:26 by jpuerto-          #+#    #+#             */
/*   Updated: 2025/02/24 14:14:12 by jpuerto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack_node
{
	int						value;
	int						index;
	int						push_cost;
	bool					above_mid;
	bool					cheapest;
	struct s_stack_node		*target;
	struct s_stack_node		*prev;
	struct s_stack_node		*next;
}				t_stack_node;

char				**ft_split(char const *s, char c);
void				free_stack(t_stack_node **stack);
void				free_matrix(char **argv);
t_stack_node		*ft_lstlast(t_stack_node *lst);
int					ft_lstsize(t_stack_node *lst);
void				throw_error(t_stack_node **a, char **matrix, bool exit);
char				*ft_strchr(const char *s, int c);
long				ft_atol(const char *str);
void				*ft_calloc(size_t nmemb, size_t size);

void				push_swap(t_stack_node **a, t_stack_node **b);
void				parse_args(char *argv, t_stack_node **a, char ***split);
void				append_node(t_stack_node **stack, int n);
int					check_num(char	*nbr);
int					check_repetition(t_stack_node *node, int nbr);

bool				is_ordered(t_stack_node *stack);	
t_stack_node		*find_max(t_stack_node *a);
t_stack_node		*find_min(t_stack_node *stack);
void				sort_three(t_stack_node **stack);
void				init_stack_a(t_stack_node **a, char **argv);
void				init_nodes_b(t_stack_node *a, t_stack_node *b);
t_stack_node		*get_cheapest(t_stack_node *a);
void				get_index(t_stack_node *stack);
void				get_price(t_stack_node *a, t_stack_node *b);
void				prepare_push(t_stack_node **stack, t_stack_node *top_node,
						char stack_name);

void				pa(t_stack_node **a, t_stack_node **b, bool print);
void				pb(t_stack_node **b, t_stack_node **a, bool print);
void				rra(t_stack_node **a, bool print);
void				rrb(t_stack_node **b, bool print);
void				rrr(t_stack_node **a, t_stack_node **b, bool print);
void				ra(t_stack_node **a, bool print);
void				rb(t_stack_node **b, bool print);
void				rr(t_stack_node **a, t_stack_node **b, bool print);
void				sa(t_stack_node	**a, bool print);
void				sb(t_stack_node **b, bool print);
void				ss(t_stack_node **a, t_stack_node **b, bool print);
void				rotate_ab(t_stack_node **a, t_stack_node **b,
						t_stack_node *cheapest);
void				rev_rotate_ab(t_stack_node **a, t_stack_node **b,
						t_stack_node *cheapest);

// BONUS
typedef struct t_gnl
{
	char		buffer[1024];
	int			bytes_read;
	int			buffer_pos;
	char		*line;
	int			i;
}				t_gnl;
char				*get_next_line(int fd);
int					check_command(char *line, t_stack_node **a,
						t_stack_node **b);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 21:32:57 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/29 00:06:55 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <unistd.h>
typedef struct s_number_info
{
	int					value;
	int					rank;
}						t_number_info;

typedef struct s_stack_node
{
	int					value;
	int					rank;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

typedef struct s_chunk_info
{
	int					count;
	int					size;
	int					remainder;
	int					total_size;
}						t_chunk_info;

typedef struct s_range
{
	int					start;
	int					end;
}						t_range;

typedef struct s_move
{
	int					rank;
	int					a_index;
	int					b_index;
	int					a_size;
	int					b_size;
	int					cost;
	int					a_cost;
	int					b_cost;
	int					a_dir;
	int					b_dir;
}						t_move;

int						assign_ranks(t_number_info *numbers, int count);

t_stack_node			*create_dummy_stack(void);
t_stack_node			*create_node(int value, int rank);
void					add_node_back(t_stack_node *stack_head,
							t_stack_node *new_node);
void					free_stack(t_stack_node **stack);

int						is_sorted(t_stack_node *stack);
void					find_and_rotate(t_stack_node *stack_a, int target_rank,
							int size);
void					execute_rotation(t_stack_node *stack, int index,
							int size);

void					op_sa(t_stack_node *stack_a);
void					op_sb(t_stack_node *stack_b);
void					op_ss(t_stack_node *stack_a, t_stack_node *stack_b);
void					op_pa(t_stack_node *stack_a, t_stack_node *stack_b);
void					op_pb(t_stack_node *stack_a, t_stack_node *stack_b);
void					op_ra(t_stack_node *stack_a);
void					op_rb(t_stack_node *stack_b);
void					op_rr(t_stack_node *stack_a, t_stack_node *stack_b);
void					op_rra(t_stack_node *stack_a);
void					op_rrb(t_stack_node *stack_b);
void					op_rrr(t_stack_node *stack_a, t_stack_node *stack_b);

void					sort_large(t_stack_node *stack_a, t_stack_node *stack_b,
							int size);

void					push_cheapest_in_range(t_stack_node *stack_a,
							t_stack_node *stack_b, t_range *range,
							int current_size_a);
int						find_index_by_rank(t_stack_node *stack,
							int target_rank);

t_stack_node			*build_stack(t_number_info *numbers, int count);

void					solver(t_stack_node *stack_a, t_stack_node *stack_b,
							int size);

int						ft_max(int a, int b);
int						ft_min(int a, int b);
void					free_split(char **split);

void					execute_best_move(t_stack_node *stack_a,
							t_stack_node *stack_b, t_move move);
t_move					find_best_move(t_stack_node *stack_a,
							t_stack_node *stack_b, int size_a, int size_b);

#endif

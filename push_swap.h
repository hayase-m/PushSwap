/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 21:32:57 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/21 23:41:25 by hmaruyam         ###   ########.fr       */
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

int						assign_ranks(t_number_info *numbers, int count);

t_stack_node			*create_dummy_stack(void);
t_stack_node			*create_node(int value, int rank);
void					add_node_back(t_stack_node *stack_head,
							t_stack_node *new_node);
void					free_stack(t_stack_node **stack);

#endif

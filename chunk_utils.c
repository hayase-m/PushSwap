/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:35:20 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/22 17:50:30 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_update_if_cheaper(int current_cost, int *min_cost, int *best_i,
		int current_i)
{
	if (*min_cost > current_cost)
	{
		*min_cost = current_cost;
		*best_i = current_i;
	}
}

static int	_find_best_index(t_stack_node *stack_a, int range_start,
		int range_end)
{
	t_stack_node	*current_node;
	int				size;
	int				min_cost;
	int				i;
	int				best_i;

	current_node = stack_a->next;
	size = count_stack_nodes(stack_a);
	min_cost = INT_MAX;
	i = 0;
	best_i = -1;
	while (current_node != stack_a)
	{
		if (((current_node->rank >= range_start)
				&& (current_node->rank <= range_end)))
		{
			if (i <= size / 2)
				_update_if_cheaper(i, &min_cost, &best_i, i);
			else
				_update_if_cheaper(size - i, &min_cost, &best_i, i);
		}
		current_node = current_node->next;
		i++;
	}
	return (best_i);
}

void	push_cheapest_in_range(t_stack_node *stack_a, t_stack_node *stack_b,
		int range_start, int range_end)
{
	int	best_index;
	int	current_size_a;

	current_size_a = count_stack_nodes(stack_a);
	best_index = _find_best_index(stack_a, range_start, range_end);
	execute_rotation(stack_a, best_index, current_size_a);
	op_pb(stack_a, stack_b);
}

int	find_index_by_rank(t_stack_node *stack, int target_rank)
{
	t_stack_node	*current_node;
	int				i;

	current_node = stack->next;
	i = 0;
	while (current_node != stack)
	{
		if (current_node->rank == target_rank)
			break ;
		i++;
		current_node = current_node->next;
	}
	return (i);
}

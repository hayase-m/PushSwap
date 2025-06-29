/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 20:31:20 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/29 00:00:00 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_find_dest_index_in_a(t_stack_node *stack_a, int target_rank)
{
	int				i;
	t_stack_node	*current_node;
	int				min_rank_index;
	int				min_rank;
	int				best_rank;
	int				best_index;

	i = 0;
	current_node = stack_a->next;
	min_rank = INT_MAX;
	best_rank = INT_MAX;
	best_index = -1;
	while (current_node != stack_a)
	{
		if (current_node->rank < min_rank)
		{
			min_rank_index = i;
			min_rank = current_node->rank;
		}
		if (current_node->rank > target_rank && current_node->rank < best_rank)
		{
			best_index = i;
			best_rank = current_node->rank;
		}
		i++;
		current_node = current_node->next;
	}
	if (best_index != -1)
		return (best_index);
	else
		return (min_rank_index);
}

static void	_calculate_cost(t_move *move)
{
	if (move->a_index <= move->a_size / 2)
	{
		move->a_cost = move->a_index;
		move->a_dir = 1;
	}
	else
	{
		move->a_cost = move->a_size - move->a_index;
		move->a_dir = -1;
	}
	if (move->b_index <= move->b_size / 2)
	{
		move->b_cost = move->b_index;
		move->b_dir = 1;
	}
	else
	{
		move->b_cost = move->b_size - move->b_index;
		move->b_dir = -1;
	}
	if ((move->a_dir == 1 && move->b_dir == 1) || (move->a_dir == -1
			&& move->b_dir == -1))
		move->cost = ft_max(move->a_cost, move->b_cost);
	else
		move->cost = move->a_cost + move->b_cost;
}

t_move	find_best_move(t_stack_node *stack_a, t_stack_node *stack_b, int size_a,
		int size_b)
{
	t_move			best_move;
	t_move			current_move;
	t_stack_node	*current_node;

	current_move.a_size = size_a;
	current_move.b_size = size_b;
	current_move.b_index = 0;
	best_move.cost = INT_MAX;
	current_node = stack_b->next;
	while (current_node != stack_b)
	{
		current_move.a_index = _find_dest_index_in_a(stack_a,
				current_node->rank);
		_calculate_cost(&current_move);
		if (current_move.cost < best_move.cost)
		{
			best_move = current_move;
			best_move.rank = current_node->rank;
		}
		current_node = current_node->next;
		current_move.b_index++;
	}
	return (best_move);
}
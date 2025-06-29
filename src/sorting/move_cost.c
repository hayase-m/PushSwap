/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 20:31:20 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/30 01:53:59 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_search_best_index(t_stack_node *stack_a, int target_rank,
		t_a_insert_info *insert_info)
{
	t_stack_node	*current_node;
	int				i;

	i = 0;
	current_node = stack_a->next;
	while (current_node != stack_a)
	{
		if (current_node->rank < insert_info->min_rank)
		{
			insert_info->min_rank_index = i;
			insert_info->min_rank = current_node->rank;
		}
		if (current_node->rank > target_rank
			&& current_node->rank < insert_info->best_rank)
		{
			insert_info->best_index = i;
			insert_info->best_rank = current_node->rank;
		}
		i++;
		current_node = current_node->next;
	}
}

static int	_find_dest_index_in_a(t_stack_node *stack_a, int target_rank)
{
	t_a_insert_info	insert_info;

	insert_info.min_rank = INT_MAX;
	insert_info.best_rank = INT_MAX;
	insert_info.best_index = -1;
	_search_best_index(stack_a, target_rank, &insert_info);
	if (insert_info.best_index != -1)
		return (insert_info.best_index);
	else
		return (insert_info.min_rank_index);
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

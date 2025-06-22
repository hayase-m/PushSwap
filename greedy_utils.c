/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 20:31:20 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/23 01:28:57 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_find_min_rank_index(t_stack_node *stack)
{
	int				i;
	t_stack_node	*current_node;
	int				min_rank_index;
	int				min_rank;

	i = 0;
	current_node = stack->next;
	min_rank = INT_MAX;
	while (current_node != stack)
	{
		if (current_node->rank < min_rank)
		{
			min_rank_index = i;
			min_rank = current_node->rank;
		}
		current_node = current_node->next;
		i++;
	}
	return (min_rank_index);
}
static int	_find_best_fit_index(t_stack_node *stack, int target_rank)
{
	int				i;
	t_stack_node	*current_node;
	int				best_rank;
	int				best_index;

	i = 0;
	current_node = stack->next;
	best_rank = INT_MAX;
	best_index = -1;
	while (current_node != stack)
	{
		if (current_node->rank > target_rank && current_node->rank < best_rank)
		{
			best_index = i;
			best_rank = current_node->rank;
		}
		i++;
		current_node = current_node->next;
	}
	return (best_index);
}

int	find_dest_index_in_a(t_stack_node *stack_a, int target_rank)
{
	t_stack_node	*current_node;
	int				i;
	int				best_index;
	int				min_rank_index;

	min_rank_index = _find_min_rank_index(stack_a);
	best_index = _find_best_fit_index(stack_a, target_rank);
	if (best_index != -1)
		return (best_index);
	else
		return (min_rank_index);
}

void	calculate_cost(t_move *move, int a_size, int b_size)
{
	int	a_cost;
	int	b_cost;

	if (move->a_index <= a_size / 2)
	{
		a_cost = move->a_index;
		move->a_dir = 1;
	}
	else
	{
		a_cost = -(a_size - move->a_index);
		move->a_dir = -1;
	}
	if (move->b_index <= b_size / 2)
	{
		b_cost = move->b_index;
		move->b_dir = 1;
	}
	else
	{
		b_cost = -(b_size - move->b_index);
		move->b_dir = -1;
	}
	if ((a_cost >= 0 && b_cost >= 0) || (a_cost < 0 && b_cost < 0))
		move->cost = ft_max(ft_abs(a_cost), ft_abs(b_cost));
	else
		move->cost = ft_abs(a_cost) + ft_abs(b_cost);
}

t_move	find_best_move(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_move			best_move;
	t_move			current_move;
	t_stack_node	*current_node;
	int				a_size;
	int				b_size;
	int				b_index;

	a_size = count_stack_nodes(stack_a);
	b_size = count_stack_nodes(stack_b);
	b_index = 0;
	current_move.b_index = 0;
	best_move.cost = INT_MAX;
	current_node = stack_b->next;
	while (current_node != stack_b)
	{
		current_move.a_index = find_dest_index_in_a(stack_a,
				current_node->rank);
		calculate_cost(&current_move, a_size, b_size);
		if (current_move.cost < best_move.cost)
		{
			best_move.cost = current_move.cost;
			best_move.rank = current_node->rank;
			best_move.a_index = current_move.a_index;
			best_move.b_index = current_move.b_index;
			best_move.a_dir = current_move.a_dir;
			best_move.b_dir = current_move.b_dir;
		}
		current_node = current_node->next;
		b_index++;
	}
	return (best_move);
}

void	execute_best_move(t_stack_node *stack_a, t_stack_node *stack_b,
		t_move move)
{
	int	a_size;
	int	b_size;

	a_size = count_stack_nodes(stack_a);
	b_size = count_stack_nodes(stack_b);
	if (move.a_dir == move.b_dir)
	{
	}
	else
	{
	}
	op_pa(stack_a, stack_b);
}

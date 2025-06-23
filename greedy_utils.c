/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 20:31:20 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/23 12:43:55 by hmaruyam         ###   ########.fr       */
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

static int	_find_dest_index_in_a(t_stack_node *stack_a, int target_rank)
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

static void	_calculate_cost(t_move *move)
{
	int	a_cost;
	int	b_cost;

	if (move->a_index <= move->a_size / 2)
	{
		a_cost = move->a_index;
		move->a_dir = 1;
	}
	else
	{
		a_cost = -(move->a_size - move->a_index);
		move->a_dir = -1;
	}
	if (move->b_index <= move->b_size / 2)
	{
		b_cost = move->b_index;
		move->b_dir = 1;
	}
	else
	{
		b_cost = -(move->b_size - move->b_index);
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
	int				b_index;

	current_move.a_size = count_stack_nodes(stack_a);
	current_move.b_size = count_stack_nodes(stack_b);
	b_index = 0;
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

static void	_execute_same_direction(t_stack_node *stack_a,
		t_stack_node *stack_b, t_move *move)
{
	int	common_rotations;
	int	remain_a_rotations;
	int	remain_b_rotations;

	if (move->a_dir == 1)
	{
		common_rotations = ft_min(move->a_index, move->b_index);
		remain_a_rotations = move->a_index - common_rotations;
		remain_b_rotations = move->b_index - common_rotations;
		while (common_rotations--)
			op_rr(stack_a, stack_b);
		while (remain_a_rotations)
			op_ra(stack_a);
		while (remain_b_rotations)
			op_rb(stack_b);
	}
	else
	{
		common_rotations = ft_min(move->a_size - move->a_index, move->b_size
				- move->b_index);
		remain_a_rotations = move->a_size - move->a_index - common_rotations;
		remain_b_rotations = move->b_size - move->b_index - common_rotations;
		while (common_rotations--)
			op_rrr(stack_a, stack_b);
		while (remain_a_rotations)
			op_rra(stack_a);
		while (remain_b_rotations)
			op_rrb(stack_b);
	}
}

static void	_execute_diff_direction(t_stack_node *stack_a,
		t_stack_node *stack_b, t_move *move)
{
	int	a_rotations;
	int	b_rotations;

	if (move->a_dir == 1)
	{
		a_rotations = move->a_index;
		b_rotations = move->b_size - move->b_index;
		while (a_rotations--)
			op_ra(stack_a);
		while (b_rotations--)
			op_rrb(stack_b);
	}
	else
	{
		a_rotations = move->a_size - move->a_index;
		b_rotations = move->b_index;
		while (a_rotations--)
			op_rra(stack_a);
		while (b_rotations--)
			op_rb(stack_b);
	}
}

void	execute_best_move(t_stack_node *stack_a, t_stack_node *stack_b,
		t_move move)
{
	if (move.a_dir == move.b_dir)
		_execute_same_direction(stack_a, stack_b, &move);
	else
	{
		_execute_diff_direction(stack_a, stack_b, &move);
	}
	op_pa(stack_a, stack_b);
}

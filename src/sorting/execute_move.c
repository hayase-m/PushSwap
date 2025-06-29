/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 00:00:00 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/29 23:52:42 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_execute_same_direction(t_stack_node *stack_a,
		t_stack_node *stack_b, t_move *move)
{
	int	common_rotations;
	int	remain_a_rotations;
	int	remain_b_rotations;

	common_rotations = ft_min(move->a_cost, move->b_cost);
	remain_a_rotations = move->a_cost - common_rotations;
	remain_b_rotations = move->b_cost - common_rotations;
	if (move->a_dir == 1)
	{
		while (common_rotations--)
			op_rr(stack_a, stack_b);
		while (remain_a_rotations--)
			op_ra(stack_a);
		while (remain_b_rotations--)
			op_rb(stack_b);
	}
	else
	{
		while (common_rotations--)
			op_rrr(stack_a, stack_b);
		while (remain_a_rotations--)
			op_rra(stack_a);
		while (remain_b_rotations--)
			op_rrb(stack_b);
	}
}

static void	_execute_diff_direction(t_stack_node *stack_a,
		t_stack_node *stack_b, t_move *move)
{
	int	a_rotations;
	int	b_rotations;

	a_rotations = move->a_cost;
	b_rotations = move->b_cost;
	if (move->a_dir == 1)
	{
		while (a_rotations--)
			op_ra(stack_a);
		while (b_rotations--)
			op_rrb(stack_b);
	}
	else
	{
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

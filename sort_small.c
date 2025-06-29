/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 00:00:00 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/29 00:00:00 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_rotation(t_stack_node *stack, int index, int size)
{
	if (index <= size / 2)
	{
		while (index-- > 0)
			op_ra(stack);
	}
	else
	{
		index = size - index;
		while (index-- > 0)
			op_rra(stack);
	}
}

void	sort_three(t_stack_node *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->next->rank;
	second = stack_a->next->next->rank;
	third = stack_a->prev->rank;
	if (is_sorted(stack_a))
		return ;
	if (first < second && second > third && first < third)
	{
		op_sa(stack_a);
		op_ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		op_rra(stack_a);
	else if (first > second && second < third && first < third)
		op_sa(stack_a);
	else if (first > second && second > third && first > third)
	{
		op_sa(stack_a);
		op_rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		op_ra(stack_a);
}

void	find_and_rotate(t_stack_node *stack_a, int target_rank, int size)
{
	t_stack_node	*current_node;
	int				index;

	current_node = stack_a->next;
	index = 0;
	while (current_node->rank != target_rank)
	{
		current_node = current_node->next;
		index++;
	}
	execute_rotation(stack_a, index, size);
}

void	sort_up_to_five(t_stack_node *stack_a, t_stack_node *stack_b, int size)
{
	find_and_rotate(stack_a, 0, size);
	op_pb(stack_a, stack_b);
	if (size == 4)
	{
		sort_three(stack_a);
		op_pa(stack_a, stack_b);
	}
	else if (size == 5)
	{
		find_and_rotate(stack_a, 1, size - 1);
		op_pb(stack_a, stack_b);
		sort_three(stack_a);
		op_pa(stack_a, stack_b);
		op_pa(stack_a, stack_b);
	}
}
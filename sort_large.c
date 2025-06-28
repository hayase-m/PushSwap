/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:52:08 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/23 22:09:59 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_push_chunks_to_b(t_stack_node *stack_a, t_stack_node *stack_b,
		t_chunk_info *info)
{
	int		i;
	int		j;
	t_range	range;
	int		current_chunk_size;
	int		current_size_a;

	i = 0;
	range.end = -1;
	current_size_a = info->total_size;
	while (i < info->count)
	{
		current_chunk_size = info->size;
		if (i < info->remainder)
			current_chunk_size++;
		range.start = range.end + 1;
		range.end = range.start + current_chunk_size - 1;
		j = 0;
		while (j < current_chunk_size)
		{
			push_cheapest_in_range(stack_a, stack_b, &range, current_size_a);
			current_size_a--;
			if (i == 0)
			{
				if (stack_b->next->rank < (range.end / 2))
					op_rb(stack_b);
			}
			j++;
		}
		i++;
	}
}

static void	_push_sorted_to_a(t_stack_node *stack_a, t_stack_node *stack_b,
		int size)
{
	t_move	move;
	int		size_a;
	int		size_b;

	size_a = 0;
	size_b = size;
	while (stack_b->next != stack_b)
	{
		move = find_best_move(stack_a, stack_b, size_a, size_b);
		execute_best_move(stack_a, stack_b, move);
		size_a++;
		size_b--;
	}
}

void	sort_large(t_stack_node *stack_a, t_stack_node *stack_b, int size)
{
	t_chunk_info	info;
	int				rank_zero_index;

	info.total_size = size;
	if (size <= 100)
		info.count = 2;
	else
		info.count = 3;
	info.size = size / info.count;
	info.remainder = size % info.count;
	_push_chunks_to_b(stack_a, stack_b, &info);
	_push_sorted_to_a(stack_a, stack_b, size);
	rank_zero_index = find_index_by_rank(stack_a, 0);
	execute_rotation(stack_a, rank_zero_index, size);
}

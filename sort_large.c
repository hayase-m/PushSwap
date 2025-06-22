/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:52:08 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/22 17:56:57 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_push_chunks_to_b(t_stack_node *stack_a, t_stack_node *stack_b,
		t_chunk_info *info)
{
	int	i;
	int	j;
	int	range_start;
	int	range_end;
	int	current_chunk_size;

	i = 0;
	range_end = -1;
	while (i < info->count)
	{
		current_chunk_size = info->size;
		if (i < info->remainder)
			current_chunk_size++;
		range_start = range_end + 1;
		range_end = range_start + current_chunk_size - 1;
		j = 0;
		while (j < current_chunk_size)
		{
			push_cheapest_in_range(stack_a, stack_b, range_start, range_end);
			j++;
		}
		i++;
	}
}
static void	_push_sorted_to_a(t_stack_node *stack_a, t_stack_node *stack_b,
		int size)
{
	int	target_rank;
	int	target_index;
	int	current_size_b;

	target_rank = size - 1;
	while (stack_b->next != stack_b)
	{
		target_index = find_index_by_rank(stack_b, target_rank);
		current_size_b = count_stack_nodes(stack_b);
		execute_rotation(stack_b, target_index, current_size_b);
		op_pa(stack_a, stack_b);
		target_rank--;
	}
}

void	sort_large(t_stack_node *stack_a, t_stack_node *stack_b, int size)
{
	t_chunk_info	info;

	info.total_size = size;
	if (size <= 150)
		info.count = 5;
	else
		info.count = 11;
	info.size = size / info.count;
	info.remainder = size % info.count;
	_push_chunks_to_b(stack_a, stack_b, &info);
	_push_sorted_to_a(stack_a, stack_b, size);
}

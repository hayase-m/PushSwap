/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 20:31:20 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/22 20:42:32 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_dest_index_in_a(t_stack_node *stack_a, int target_rank)
{
	int	i;
	int	best_index;
	int	min_rank_index;

	i = 0;
	best_index = INT_MAX;
	while (stack_a->next != stack_a)
	{
	}
	while (stack_a->next != stack_a)
	{
		if (stack_a->rank > target_rank && stack_a->rank < best_index)
			best_index = i;
		i++;
	}
}

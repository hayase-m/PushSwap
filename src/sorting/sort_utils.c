/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:21:59 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/29 23:52:49 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack_node *stack)
{
	t_stack_node	*current_node;

	current_node = stack->next;
	if ((stack->next == stack) || (stack->next->next == stack))
		return (1);
	while (current_node->next != stack)
	{
		if (current_node->rank > current_node->next->rank)
			return (0);
		current_node = current_node->next;
	}
	return (1);
}

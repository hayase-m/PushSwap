/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 01:54:08 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/22 12:42:16 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_swap_stack(t_stack_node *stack)
{
	t_stack_node	*first_node;
	t_stack_node	*second_node;
	t_stack_node	*third_node;

	first_node = stack->next;
	second_node = stack->next->next;
	third_node = stack->next->next->next;
	stack->next = second_node;
	second_node->prev = stack;
	second_node->next = first_node;
	first_node->prev = second_node;
	first_node->next = third_node;
	third_node->prev = first_node;
}

void	op_sa(t_stack_node *stack_a)
{
	if ((stack_a->next == stack_a) || (stack_a->next->next == stack_a))
		return ;
	_swap_stack(stack_a);
	write(1, "sa\n", 3);
}

void	op_sb(t_stack_node *stack_b)
{
	if ((stack_b->next == stack_b) || (stack_b->next->next == stack_b))
		return ;
	_swap_stack(stack_b);
	write(1, "sb\n", 3);
}

void	op_ss(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int	swapped_a;
	int	swapped_b;

	swapped_a = !((stack_a->next == stack_a)
			|| (stack_a->next->next == stack_a));
	swapped_b = !((stack_b->next == stack_b)
			|| (stack_b->next->next == stack_b));
	if (swapped_a && swapped_b)
	{
		_swap_stack(stack_a);
		_swap_stack(stack_b);
		write(1, "ss\n", 3);
	}
}

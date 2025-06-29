/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 12:42:38 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/22 13:01:10 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_reverse_rotate_stack(t_stack_node *stack)
{
	t_stack_node	*last_node;
	t_stack_node	*first_node;
	t_stack_node	*second_last_node;

	last_node = stack->prev;
	first_node = stack->next;
	second_last_node = stack->prev->prev;
	second_last_node->next = stack;
	stack->prev = second_last_node;
	stack->next = last_node;
	last_node->prev = stack;
	last_node->next = first_node;
	first_node->prev = last_node;
}

void	op_rra(t_stack_node *stack_a)
{
	if ((stack_a->next == stack_a) || (stack_a->next->next == stack_a))
		return ;
	_reverse_rotate_stack(stack_a);
	write(1, "rra\n", 4);
}

void	op_rrb(t_stack_node *stack_b)
{
	if ((stack_b->next == stack_b) || (stack_b->next->next == stack_b))
		return ;
	_reverse_rotate_stack(stack_b);
	write(1, "rrb\n", 4);
}

void	op_rrr(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int	can_reverse_rotate_a;
	int	can_reverse_rotate_b;

	can_reverse_rotate_a = !((stack_a->next == stack_a)
			|| (stack_a->next->next == stack_a));
	can_reverse_rotate_b = !((stack_b->next == stack_b)
			|| (stack_b->next->next == stack_b));
	if (can_reverse_rotate_a && can_reverse_rotate_b)
	{
		_reverse_rotate_stack(stack_a);
		_reverse_rotate_stack(stack_b);
		write(1, "rrr\n", 4);
	}
}

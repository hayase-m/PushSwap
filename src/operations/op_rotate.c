/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 12:13:02 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/22 12:40:54 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_rotate_stack(t_stack_node *stack)
{
	t_stack_node	*last_node;
	t_stack_node	*first_node;
	t_stack_node	*second_node;

	last_node = stack->prev;
	first_node = stack->next;
	second_node = stack->next->next;
	last_node->next = first_node;
	first_node->prev = last_node;
	first_node->next = stack;
	stack->prev = first_node;
	stack->next = second_node;
	second_node->prev = stack;
}

void	op_ra(t_stack_node *stack_a)
{
	if ((stack_a->next == stack_a) || (stack_a->next->next == stack_a))
		return ;
	_rotate_stack(stack_a);
	write(1, "ra\n", 3);
}

void	op_rb(t_stack_node *stack_b)
{
	if ((stack_b->next == stack_b) || (stack_b->next->next == stack_b))
		return ;
	_rotate_stack(stack_b);
	write(1, "rb\n", 3);
}

void	op_rr(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int	can_rotate_a;
	int	can_rotate_b;

	can_rotate_a = !((stack_a->next == stack_a)
			|| (stack_a->next->next == stack_a));
	can_rotate_b = !((stack_b->next == stack_b)
			|| (stack_b->next->next == stack_b));
	if (can_rotate_a && can_rotate_b)
	{
		_rotate_stack(stack_a);
		_rotate_stack(stack_b);
		write(1, "rr\n", 3);
	}
}

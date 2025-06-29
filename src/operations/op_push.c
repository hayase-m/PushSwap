/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 11:41:45 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/30 01:02:07 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_push_stack(t_stack_node *dst_stack, t_stack_node *src_stack)
{
	t_stack_node	*head_dst;
	t_stack_node	*head_src;
	t_stack_node	*second_src;

	head_dst = dst_stack->next;
	head_src = src_stack->next;
	second_src = head_src->next;
	src_stack->next = second_src;
	second_src->prev = src_stack;
	dst_stack->next = head_src;
	head_src->prev = dst_stack;
	head_src->next = head_dst;
	head_dst->prev = head_src;
}

void	op_pa(t_stack_node *stack_a, t_stack_node *stack_b)
{
	if (stack_b->next == stack_b)
		return ;
	_push_stack(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	op_pb(t_stack_node *stack_a, t_stack_node *stack_b)
{
	if (stack_a->next == stack_a)
		return ;
	_push_stack(stack_b, stack_a);
	write(1, "pb\n", 3);
}

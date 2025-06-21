/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 01:54:08 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/22 02:31:28 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	_swap_stack(t_stack_node *stack)
{
	t_stack_node	*first_node;
	t_stack_node	*second_node;
	t_stack_node	*third_node;

	first_node = stack->next;
	second_node = stack->next->next;
	third_node = stack->next->next->next;
	if ((first_node == stack) || (second_node == stack))
		return (0);
	stack->next = second_node;
	second_node->prev = stack;
	second_node->next = first_node;
	first_node->prev = second_node;
	first_node->next = third_node;
	third_node->prev = first_node;
	return (1);
}

void	op_sa(t_stack_node *stack_a)
{
	if (!(_swap_stack(stack_a)))
		return ;
	write(1, "sa\n", 3);
}

void	op_sb(t_stack_node *stack_b)
{
	if (!(_swap_stack(stack_b)))
		return ;
	write(1, "sb\n", 3);
}

void	op_ss(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int	swapped_a;
	int	swapped_b;

	swapped_a = _swap_stack(stack_a);
	swapped_b = _swap_stack(stack_b);
	if (swapped_a || swapped_b)
	{
		write(1, "ss\n", 3);
	}
}

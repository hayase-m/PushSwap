/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 14:20:56 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/29 23:52:44 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solver(t_stack_node *stack_a, t_stack_node *stack_b, int size)
{
	if (is_sorted(stack_a))
		return ;
	if (size == 2)
		op_sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_up_to_five(stack_a, stack_b, size);
	else if (size > 5)
		sort_large(stack_a, stack_b, size);
}

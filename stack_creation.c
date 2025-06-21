/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 23:17:12 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/21 23:44:59 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*build_stack_a(t_number_info *numbers, int count)
{
	t_stack_node	*stack_a;
	t_stack_node	*new_node;
	int				i;

	i = 0;
	stack_a = create_dummy_stack();
	if (!stack_a)
		return (NULL);
	while (i < count)
	{
		new_node = create_node(numbers[i].value, numbers[i].rank);
		if (!new_node)
		{
			free_stack(&stack_a);
			return (NULL);
		}
		add_node_back(stack_a, new_node);
		i++;
	}
	return (stack_a);
}

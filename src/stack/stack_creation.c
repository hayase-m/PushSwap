/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 23:17:12 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/22 18:00:07 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*build_stack(t_number_info *numbers, int count)
{
	t_stack_node	*stack;
	t_stack_node	*new_node;
	int				i;

	i = 0;
	stack = create_dummy_stack();
	if (!stack)
		return (NULL);
	while (i < count)
	{
		new_node = create_node(numbers[i].value, numbers[i].rank);
		if (!new_node)
		{
			free_stack(&stack);
			return (NULL);
		}
		add_node_back(stack, new_node);
		i++;
	}
	return (stack);
}

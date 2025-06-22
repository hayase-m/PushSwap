/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 22:34:59 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/22 16:56:05 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*create_dummy_stack(void)
{
	t_stack_node	*dummy_node;

	dummy_node = malloc(sizeof(t_stack_node));
	if (!dummy_node)
		return (NULL);
	dummy_node->value = 0;
	dummy_node->rank = -1;
	dummy_node->prev = dummy_node;
	dummy_node->next = dummy_node;
	return (dummy_node);
}

t_stack_node	*create_node(int value, int rank)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->rank = rank;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
void	add_node_back(t_stack_node *stack_head, t_stack_node *new_node)
{
	t_stack_node	*last_node;

	last_node = stack_head->prev;
	new_node->next = stack_head;
	new_node->prev = last_node;
	last_node->next = new_node;
	stack_head->prev = new_node;
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*current_node;
	t_stack_node	*tmp_node;

	current_node = (*stack)->next;
	while (current_node != *stack)
	{
		tmp_node = current_node;
		current_node = current_node->next;
		free(tmp_node);
	}
	free(*stack);
	*stack = NULL;
}
int	count_stack_nodes(t_stack_node *stack)
{
	int				count;
	t_stack_node	*current_node;

	count = 0;
	current_node = stack->next;
	while (current_node != stack)
	{
		current_node = current_node->next;
		count++;
	}
	return (count);
}

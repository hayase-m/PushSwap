/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 22:25:34 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/29 23:52:54 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, const char *argv[])
{
	int				count;
	t_number_info	*numbers;
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	if (argc == 1)
		return (0);
	numbers = NULL;
	init_numbers_from_args(argc, argv, &numbers, &count);
	stack_a = build_stack(numbers, count);
	free(numbers);
	if (!stack_a)
		handle_error();
	stack_b = create_dummy_stack();
	if (!stack_b)
	{
		free_stack(&stack_a);
		handle_error();
	}
	solver(stack_a, stack_b, count);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

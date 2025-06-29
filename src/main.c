/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 22:25:34 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/29 00:00:00 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*_join_all_args(int argc, const char **argv)
{
	char	*full_str;
	char	*tmp;
	int		i;

	full_str = ft_strdup(argv[1]);
	if (!full_str)
		return (NULL);
	i = 2;
	while (i < argc)
	{
		tmp = full_str;
		full_str = ft_strjoin(tmp, " ");
		free(tmp);
		if (!full_str)
			return (NULL);
		tmp = full_str;
		full_str = ft_strjoin(tmp, argv[i]);
		free(tmp);
		if (!full_str)
			return (NULL);
		i++;
	}
	return (full_str);
}

int	main(int argc, const char *argv[])
{
	int				count;
	char			*full_str;
	char			**split_str;
	t_number_info	*numbers;
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	if (argc == 1)
		return (0);
	numbers = NULL;
	full_str = _join_all_args(argc, argv);
	if (!full_str)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	split_str = ft_split(full_str, ' ');
	free(full_str);
	if (!split_str)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	count = 0;
	while (split_str[count] != NULL)
		count++;
	if (validate_and_parse_args(count, split_str, &numbers) == 0)
	{
		free_split(split_str);
		write(2, "Error\n", 6);
		return (1);
	}
	free_split(split_str);
	if (!assign_ranks(numbers, count))
	{
		free(numbers);
		write(2, "Error\n", 6);
		return (1);
	}
	stack_a = build_stack(numbers, count);
	free(numbers);
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_b = create_dummy_stack();
	if (!stack_b)
	{
		free_stack(&stack_a);
		write(2, "Error\n", 6);
		return (1);
	}
	solver(stack_a, stack_b, count);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
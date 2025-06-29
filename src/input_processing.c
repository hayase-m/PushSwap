/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 00:00:00 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/29 23:48:29 by hmaruyam         ###   ########.fr       */
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

int	init_numbers_from_args(int argc, const char **argv, t_number_info **numbers,
		int *count)
{
	char	*full_str;
	char	**split_str;

	full_str = _join_all_args(argc, argv);
	if (!full_str)
		handle_error();
	split_str = ft_split(full_str, ' ');
	free(full_str);
	if (!split_str)
		handle_error();
	*count = 0;
	while (split_str[*count] != NULL)
		(*count)++;
	if (validate_and_parse_args(*count, split_str, numbers) == 0)
	{
		free_split(split_str);
		handle_error();
	}
	free_split(split_str);
	if (!assign_ranks(*numbers, *count))
	{
		free(*numbers);
		handle_error();
	}
	return (1);
}

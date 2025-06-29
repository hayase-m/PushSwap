/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 00:00:00 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/30 01:02:33 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicates(t_number_info *numbers, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (numbers[i].value == numbers[j].value)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	process_single_number(const char *str, t_number_info *num_info)
{
	long long	converted_value;

	if (!ft_atoll(str, &converted_value))
		return (0);
	if (converted_value > INT_MAX || converted_value < INT_MIN)
		return (0);
	num_info->value = (int)converted_value;
	num_info->rank = -1;
	return (1);
}

int	validate_and_parse_args(int count, char **split_str,
		t_number_info **numbers)
{
	int	i;

	*numbers = malloc(sizeof(t_number_info) * count);
	if (!(*numbers))
		return (0);
	i = 0;
	while (i < count)
	{
		if (!process_single_number(split_str[i], &(*numbers)[i]))
		{
			free(*numbers);
			return (0);
		}
		i++;
	}
	if (has_duplicates(*numbers, count))
	{
		free(*numbers);
		return (0);
	}
	return (1);
}

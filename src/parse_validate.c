/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 00:00:00 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/29 00:00:00 by hmaruyam         ###   ########.fr       */
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

int	ft_atoll(const char *str, long long *result)
{
	int		i;
	int	sign;
	long long	res;
	int		digit_count;

	i = 0;
	sign = 1;
	digit_count = 0;
	res = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		digit_count++;
		if ((sign == 1 && (res > LLONG_MAX / 10 || (res == LLONG_MAX / 10
						&& (str[i] - '0') > LLONG_MAX % 10))) || (sign == -1
				&& (res > LLONG_MAX / 10 || (res == LLONG_MAX / 10 && (str[i]
							- '0') > (LLONG_MAX % 10) + 1))))
			return (0);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (digit_count == 0)
		return (0);
	*result = res * sign;
	return (1);
}

int	validate_and_parse_args(int count, char **split_str,
		t_number_info **numbers)
{
	int		i;
	long long	converted_value;

	*numbers = malloc(sizeof(t_number_info) * count);
	if (!(*numbers))
		return (0);
	i = 0;
	while (i < count)
	{
		if (!ft_atoll(split_str[i], &converted_value))
		{
			free(*numbers);
			return (0);
		}
		if (converted_value > INT_MAX || converted_value < INT_MIN)
		{
			free(*numbers);
			return (0);
		}
		(*numbers)[i].value = (int)converted_value;
		(*numbers)[i].rank = -1;
		i++;
	}
	if (has_duplicates(*numbers, count))
	{
		free(*numbers);
		return (0);
	}
	return (1);
}

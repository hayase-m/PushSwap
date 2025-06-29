/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 00:00:00 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/30 01:02:27 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_overflow(long long res, int sign, int digit)
{
	if (sign == 1)
	{
		if (res > LLONG_MAX / 10 || (res == LLONG_MAX / 10 && digit > LLONG_MAX
				% 10))
			return (1);
	}
	else
	{
		if (res > LLONG_MAX / 10 || (res == LLONG_MAX / 10 && digit > (LLONG_MAX
					% 10) + 1))
			return (1);
	}
	return (0);
}

static int	parse_numeric_part(const char *s, int *idx, int sign,
		long long *current_res)
{
	int	digit_count;

	digit_count = 0;
	while (s[*idx])
	{
		if (s[*idx] < '0' || s[*idx] > '9')
			return (0);
		digit_count++;
		if (is_overflow(*current_res, sign, s[*idx] - '0'))
			return (0);
		*current_res = *current_res * 10 + (s[*idx] - '0');
		(*idx)++;
	}
	if (digit_count == 0)
		return (0);
	return (1);
}

int	ft_atoll(const char *str, long long *result)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!parse_numeric_part(str, &i, sign, &res))
		return (0);
	*result = res * sign;
	return (1);
}

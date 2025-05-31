/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 22:25:34 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/01 00:30:30 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_within_int_range(char *str)
{
	int			i;
	int			digit_count;
	int			sign;
	long long	result;

	i = 0;
	digit_count = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	result = 0;
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
		digit_count++;
	}
	if (digit_count > 10)
		return (0);
	if (sign == 1)
	{
		if (result > (long long)INT_MAX)
			return (0);
	}
	else
	{
		if (result > -((long long)INT_MIN))
			return (0);
	}
	return (1);
}

int	is_valid_input(int argc, const *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (!argv[i][j])
			return (0);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		if (!(is_within_int_range(argv[i])))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char const *argv[])
{
	if (argc == 1)
		return (0);
	if (is_valid_input(argc, argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	return (0);
}

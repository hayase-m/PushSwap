/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:12:38 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/04/25 16:52:01 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_cut_value_and_digit(int sign, unsigned long *cut_value,
		int *cut_digit)
{
	if (sign == 1)
	{
		*cut_value = LONG_MAX / 10;
		*cut_digit = LONG_MAX % 10;
	}
	else
	{
		*cut_value = ((unsigned long)LONG_MAX + 1) / 10;
		*cut_digit = ((unsigned long)LONG_MAX + 1) % 10;
	}
}

static int	return_if_over(int sign)
{
	if (sign == 1)
		return (-1);
	else
		return (0);
}

static int	execute_conversion(const char *str, int sign)
{
	unsigned long	result;
	int				digit;
	unsigned long	cut_value;
	int				cut_digit;

	result = 0;
	set_cut_value_and_digit(sign, &cut_value, &cut_digit);
	while ((*str >= '0' && *str <= '9'))
	{
		digit = *str - '0';
		if ((result > cut_value) || (result == cut_value && digit > cut_digit))
			return (return_if_over(sign));
		result = result * 10 + (*str - '0');
		str++;
	}
	return ((int)(sign * result));
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	return (execute_conversion(&str[i], sign));
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	printf("%d\n", ft_atoi("+32112"));
// 	printf("%d\n", ft_atoi("-32112"));
// 	printf("%d\n", ft_atoi("9223372036854775809"));
// 	printf("%d\n", atoi("9223372036854775809"));
// 	return (0);
// }

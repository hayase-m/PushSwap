/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:53:06 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/21 23:22:28 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	assign_ranks(t_number_info *numbers, int count)
{
	t_number_info	*copy_numbers;
	int				i;
	int				j;
	int				temp;

	copy_numbers = malloc(sizeof(t_number_info) * count);
	if (!copy_numbers)
		return (0);
	ft_memcpy(copy_numbers, numbers, sizeof(t_number_info) * count);
	i = 0;
	j = 0;
	while (i < count)
	{
		j = 0;
		while (j < count - 1 - i)
		{
			if (copy_numbers[j].value > copy_numbers[j + 1].value)
			{
				temp = copy_numbers[j].value;
				copy_numbers[j].value = copy_numbers[j + 1].value;
				copy_numbers[j + 1].value = temp;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count)
		{
			if (copy_numbers[i].value == numbers[j].value)
				numbers[j].rank = i;
			j++;
		}
		i++;
	}
	free(copy_numbers);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:53:06 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/06/30 00:43:38 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_number(t_number_info *numbers, int count)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count - 1 - i)
		{
			if (numbers[j].value > numbers[j + 1].value)
			{
				temp = numbers[j].value;
				numbers[j].value = numbers[j + 1].value;
				numbers[j + 1].value = temp;
			}
			j++;
		}
		i++;
	}
}

int	assign_ranks(t_number_info *numbers, int count)
{
	t_number_info	*copy_numbers;
	int				i;
	int				j;

	copy_numbers = malloc(sizeof(t_number_info) * count);
	if (!copy_numbers)
		return (0);
	ft_memcpy(copy_numbers, numbers, sizeof(t_number_info) * count);
	sort_number(copy_numbers, count);
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

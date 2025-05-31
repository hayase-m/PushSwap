/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:30:55 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/04/29 00:38:17 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	if (!count || !size)
	{
		result = malloc(1);
		if (!result)
			return (NULL);
		return (result);
	}
	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	result = malloc(count * size);
	if (!result)
		return (NULL);
	ft_memset(result, 0, count * size);
	return (result);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int	main(void)
// {
// 	int		*ptr1;
// 	size_t	count1;
// 	size_t	size1;
// 	char	zeros[sizeof(int) * 5];
// 	void	*ptr_zero;

// 	count1 = 5;
// 	size1 = sizeof(int);
// 	ptr1 = (int *)ft_calloc(count1, size1);
// 	memset(zeros, 0, count1 * size1);
// 	if (memcmp(ptr1, zeros, count1 * size1) == 0)
// 		printf("Test 1: OK\n");
// 	else
// 		printf("Test 1: KO (Not zeroed)\n");
// 	ptr_zero = ft_calloc(10, 0);
// 	if (ptr_zero != NULL)
// 		printf("Test 2: OK\n");
// 	else
// 		printf("Test 2: KO (NULL returned for size 0)\n");
// 	return (0);
// }
// void	*ft_memset(void *b, int c, size_t len)
// {
// 	size_t			i;
// 	unsigned char	*str;

// 	str = (unsigned char *)b;
// 	i = 0;
// 	while (i < len)
// 	{
// 		str[i] = (unsigned char)c;
// 		i++;
// 	}
// 	return (b);
// }

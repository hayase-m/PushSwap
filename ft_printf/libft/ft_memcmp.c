/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:17:22 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/04/25 16:57:45 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*uc_s1;
	const unsigned char	*uc_s2;

	i = 0;
	uc_s1 = (const unsigned char *)s1;
	uc_s2 = (const unsigned char *)s2;
	while (i < n && uc_s1[i] == uc_s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)uc_s1[i] - (unsigned char)uc_s2[i]);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int				result;
// 	unsigned char	b1[] = {10, 20, 30, 40, 50};
// 	unsigned char	b2[] = {10, 20, 30, 40, 50};
// 	unsigned char	b3[] = {10, 20, 35, 40, 50};

// 	result = ft_memcmp(b1, b2, 5);
// 	printf("Result 1 (b1 vs b2, n=5): %d\n", result);
// 	result = ft_memcmp(b1, b3, 5);
// 	printf("Result 2 (b1 vs b3, n=5): %d\n", result);
// 	return (0);
// }

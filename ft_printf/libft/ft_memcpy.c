/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 23:03:09 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/04/22 20:41:39 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*uc_dst;
	const unsigned char	*uc_src;

	uc_dst = (unsigned char *)dst;
	uc_src = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		uc_dst[i] = uc_src[i];
		i++;
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	src[] = "Test String";
// 	char	dst[20];
// 	size_t	n;

// 	n = strlen(src) + 1;
// 	memset(dst, 'X', sizeof(dst) - 1);
// 	dst[sizeof(dst) - 1] = '\0';
// 	printf("Before memcpy, dst: %s\n", dst);
// 	ft_memcpy(dst, src, n);
// 	printf("After ft_memcpy,  dst: %s\n", dst);
// 	if (memcmp(dst, src, n) == 0)
// 	{
// 		printf("Result: OK\n");
// 	}
// 	else
// 	{
// 		printf("Result: KO\n");
// 	}
// 	return (0);
// }

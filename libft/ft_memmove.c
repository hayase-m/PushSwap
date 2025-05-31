/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 23:33:31 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/04/25 14:58:18 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*uc_dst;
	const unsigned char	*uc_src;
	int					direction;

	i = 0;
	direction = 1;
	uc_dst = (unsigned char *)dst;
	uc_src = (const unsigned char *)src;
	if (dst == src || len == 0)
		return (dst);
	if (uc_dst > uc_src && uc_dst < uc_src + len)
	{
		direction = -1;
		i = len - 1;
	}
	while (0 < len)
	{
		uc_dst[i] = uc_src[i];
		i += direction;
		len--;
	}
	return (dst);
}
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	buffer1[30];
// 	char	buffer2[30];
// 	char	*src_start_str;

// 	src_start_str = "abcdefghij";
// 	strcpy(buffer1, src_start_str);
// 	strcpy(buffer2, src_start_str);
// 	ft_memmove(buffer1 + 2, buffer1, 8);
// 	memmove(buffer2 + 2, buffer2, 8);
// 	printf("%s\n", buffer1);
// 	printf("%s\n", buffer2);
// 	ft_memmove(buffer1, buffer1 + 2, 8);
// 	memmove(buffer2, buffer2 + 2, 8);
// 	printf("%s\n", buffer1);
// 	printf("%s\n", buffer2);
// 	return (0);
// }

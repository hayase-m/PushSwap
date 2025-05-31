/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 23:28:20 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/04/22 20:53:31 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	d_len = 0;
	while (dst[d_len] && d_len < size)
		d_len++;
	s_len = 0;
	while (src[s_len])
		s_len++;
	if (size <= d_len)
		return (size + s_len);
	i = 0;
	while (src[i] && d_len + i < size - 1)
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char			dest1[8] = "Hello, ";
// 	char			*src;
// 	unsigned int	size;
// 	unsigned int	result1;

// 	src = "World!testtesttest";
// 	size = 4;
// 	printf("Before ft_strlcat: \"%s\"\n", dest1);
// 	result1 = ft_strlcat(dest1, src, size);
// 	printf("After ft_strlcat:  \"%s\"\n", dest1);
// 	printf("Return value: %u\n", result1);
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 23:26:18 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/04/22 20:55:22 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	if (size == 0)
		return (i);
	while (j < (size - 1) && src[j] != '\0')
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char			src[] = "Hello, 42Tokyo!";
// 	char			dest1[20];
// 	char			dest2[20];
// 	unsigned int	len1;
// 	unsigned int	len2;

// 	len1 = ft_strlcpy(dest1, src, 10);
// 	len2 = ft_strlcpy(dest2, src, 4);
// 	printf("10文字: \"%s\" (len: %u)\n", dest1, len1);
// 	printf("4文字:    \"%s\" (len: %u)\n", dest2, len2);
// 	return (0);
// }

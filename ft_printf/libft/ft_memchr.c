/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:00:23 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/04/24 21:14:15 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*uc_s;

	i = 0;
	uc_s = (const unsigned char *)s;
	while (i < n)
	{
		if (uc_s[i] == (unsigned char)c)
			return ((void *)(uc_s + i));
		i++;
	}
	return (NULL);
}
// #include <stdio.h>

// int	main(void)
// {
// 	void		*result;
// 	const char	*test_str = "Hello World!";

// 	printf("Testing string: \"%s\"\n", test_str);
// 	result = ft_memchr(test_str, 'W', 13);
// 	printf("Finding 'W' in 13 bytes: %p", result);
// 	result = ft_memchr(test_str, 'z', 13);
// 	printf("Finding 'z' in 13 bytes: %p\n", result);
// 	return (0);
// }

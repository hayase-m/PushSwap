/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:27:03 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/04/22 16:06:47 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && i + j < len && haystack[i + j] == needle[j])
			j++;
		if (!needle[j])
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
// #include <stdio.h>

// int	main(void)
// {
// 	const char	*big_str = "This is a test string for testing.";
// 	const char	*needle_found = "test";
// 	char		*result;

// 	result = ft_strnstr(big_str, needle_found, 35);
// 	printf("%s\n", result);
// 	result = ft_strnstr("", "coucou", -1);
// 	printf("%s\n", result);
// 	return (0);
// }

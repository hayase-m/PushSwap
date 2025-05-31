/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:23:56 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/04/25 17:00:03 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, s1_len);
	ft_memcpy(result + s1_len, s2, s2_len);
	result[s1_len + s2_len] = '\0';
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	str1[] = "Hello";
// 	char	str2[] = ",World";

// 	printf("%s\n", ft_strjoin(str1, str2));
// 	return (0);
// }

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// void	*ft_memcpy(void *dst, const void *src, size_t n)
// {
// 	size_t				i;
// 	unsigned char		*uc_dst;
// 	const unsigned char	*uc_src;

// 	uc_dst = (unsigned char *)dst;
// 	uc_src = (const unsigned char *)src;
// 	i = 0;
// 	while (i < n)
// 	{
// 		uc_dst[i] = uc_src[i];
// 		i++;
// 	}
// 	return (dst);
// }

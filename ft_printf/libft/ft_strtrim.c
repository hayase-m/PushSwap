/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:46:16 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/04/25 16:52:51 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_index;
	size_t	end_index;
	size_t	s1_len;
	char	*result;

	start_index = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	end_index = s1_len;
	while (s1[start_index] && ft_strchr(set, s1[start_index]))
		start_index++;
	while (end_index > start_index && ft_strchr(set, s1[end_index - 1]))
		end_index--;
	result = malloc(sizeof(char) * (end_index - start_index + 1));
	if (!result)
		return (NULL);
	ft_memcpy(result, s1 + start_index, end_index - start_index);
	result[end_index - start_index] = '\0';
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	str[] = "_abc_def____";
// 	char	set[] = "_";

// 	printf("%s\n", ft_strtrim(str, set));
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

// char	*ft_strchr(const char *s, int c)
// {
// 	size_t	len;
// 	size_t	i;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	i = 0;
// 	while (i <= len)
// 	{
// 		if (s[i] == (char)c)
// 			return ((char *)s + i);
// 		i++;
// 	}
// 	return (NULL);
// }

// char	*ft_strdup(const char *s1)
// {
// 	char	*result;
// 	size_t	s1_len;
// 	size_t	i;

// 	i = 0;
// 	s1_len = ft_strlen(s1);
// 	result = malloc((s1_len + 1) * sizeof(char));
// 	if (!result)
// 		return (NULL);
// 	while (i < s1_len)
// 	{
// 		result[i] = s1[i];
// 		i++;
// 	}
// 	result[s1_len] = '\0';
// 	return (result);
// }

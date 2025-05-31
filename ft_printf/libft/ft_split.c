/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:28:21 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/04/25 18:41:23 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	free_split_memory(char **result, size_t i)
{
	while (i > 0)
	{
		i--;
		free(result[i]);
	}
	free(result);
	return (0);
}

static size_t	count_words(char const *s, char c)
{
	int		is_word;
	size_t	i;
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	is_word = 0;
	i = 0;
	while (s[i])
	{
		if (!is_word && s[i] != c)
		{
			is_word = 1;
			count++;
		}
		else if (is_word && s[i] == c)
			is_word = 0;
		i++;
	}
	return (count);
}

static int	fill_result(size_t words_num, char const *s, char c, char **result)
{
	size_t	start_index;
	size_t	str_len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < words_num)
	{
		while (s[i] && s[i] == c)
			i++;
		start_index = i;
		while (s[i] && s[i] != c)
			i++;
		str_len = i - start_index;
		result[j] = malloc(sizeof(char) * (str_len + 1));
		if (!result[j])
			return (free_split_memory(result, j));
		ft_memcpy(result[j], s + start_index, str_len);
		result[j][str_len] = '\0';
		j++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	words_num;
	char	**result;

	if (!s)
		return (NULL);
	words_num = count_words(s, c);
	result = malloc(sizeof(char *) * (words_num + 1));
	if (!result)
		return (NULL);
	if (!fill_result(words_num, s, c, result))
		return (NULL);
	result[words_num] = NULL;
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	src[] = "Hello World  test";
// 	char	c;
// 	char	**result;

// 	c = ' ';
// 	result = ft_split(src, c);
// 	printf("%s\n", result[2]);
// 	return (0);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:04:03 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/04/26 17:42:42 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*check_start_index(void)
{
	char	*result;

	result = malloc(1);
	if (!result)
		return (NULL);
	result[0] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	s_len;
	size_t	i;
	size_t	copy_len;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start)
		return (check_start_index());
	if (s_len - start > len)
		copy_len = len;
	else
		copy_len = s_len - start;
	result = malloc(sizeof(char) * (copy_len + 1));
	if (!result)
		return (NULL);
	while (i < copy_len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[copy_len] = '\0';
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	str[] = "Hello,World";
// 	char	*result;

// 	result = ft_substr(str, 6, 5);
// 	printf("%s\n", result);
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

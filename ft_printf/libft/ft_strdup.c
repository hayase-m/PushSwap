/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 23:54:08 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/04/22 20:51:47 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	s1_len;
	size_t	i;

	i = 0;
	s1_len = ft_strlen(s1);
	result = malloc((s1_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (i < s1_len)
	{
		result[i] = s1[i];
		i++;
	}
	result[s1_len] = '\0';
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*str;

// 	str = "Hello,World";
// 	printf("%s\n", ft_strdup(str));
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

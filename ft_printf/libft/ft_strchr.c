/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:54:29 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/04/22 20:50:48 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (s[len])
		len++;
	i = 0;
	while (i <= len)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	str[] = "Hello";

// 	printf("%p\n", str);
// 	printf("%p\n", ft_strchr(str, 'e'));
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

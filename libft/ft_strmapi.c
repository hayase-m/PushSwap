/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:34:03 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/04/22 14:36:44 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			s_len;
	unsigned int	i;
	char			*result;

	if (!s || !f)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	result = malloc(sizeof(char) * (s_len + 1));
	if (!result)
		return (NULL);
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[s_len] = '\0';
	return (result);
}

// #include <stdio.h>

// static char	toupper_even(unsigned int i, char c)
// {
// 	if (i % 2 == 0 && (c >= 'a' && c <= 'z'))
// 		return (c -= 32);
// 	else
// 		return (c);
// }

// int	main(void)
// {
// 	char	str[] = "hello,world";

// 	printf("%s\n", ft_strmapi(str, toupper_even));
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

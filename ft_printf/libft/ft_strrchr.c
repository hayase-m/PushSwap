/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 22:39:45 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/04/22 15:24:57 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_found;
	char	target;

	last_found = NULL;
	target = (char)c;
	if (s == NULL)
		return (NULL);
	while (1)
	{
		if (*s == target)
		{
			last_found = (char *)s;
		}
		if (*s == '\0')
		{
			break ;
		}
		s++;
	}
	return (last_found);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	str[] = "Helloe";

// 	printf("%p\n", str);
// 	printf("%p\n", ft_strchr(str, '\0'));
// 	return (0);
// }

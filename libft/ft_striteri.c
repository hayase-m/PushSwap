/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:55:34 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/04/22 14:36:27 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>

// static void	toupper_even(unsigned int i, char *c)
// {
// 	if (i % 2 == 0)
// 	{
// 		if (*c >= 'a' && *c <= 'z')
// 			*c = *c - 32;
// 	}
// }

// int	main(void)
// {
// 	char	str[] = "hello,world";

// 	ft_striteri(str, toupper_even);
// 	printf("%s\n", str);
// 	return (0);
// }

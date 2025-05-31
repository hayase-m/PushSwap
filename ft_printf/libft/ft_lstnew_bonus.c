/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:28:18 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/04/24 16:11:11 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*str;
// 	t_list	*node;

// 	str = "Hello,world";
// 	node = ft_lstnew(str);
// 	printf("%s\n", (char *)node->content);
// 	return (0);
// }

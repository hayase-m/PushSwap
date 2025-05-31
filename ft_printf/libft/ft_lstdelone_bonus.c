/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:38:12 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/04/24 22:34:46 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// #include <stdio.h>

// void	simple_free(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	t_list	*the_node;
// 	char	*dynamic_content;

// 	dynamic_content = ft_strdup("content");
// 	the_node = ft_lstnew(dynamic_content);
// 	printf("%s\n", (char *)the_node->content);
// 	ft_lstdelone(the_node, simple_free);
// 	printf("%s\n", (char *)the_node->content);
// 	return (0);
// }

// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*new_node;

// 	new_node = malloc(sizeof(t_list));
// 	if (!new_node)
// 		return (NULL);
// 	new_node->content = content;
// 	new_node->next = NULL;
// 	return (new_node);
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

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

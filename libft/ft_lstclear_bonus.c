/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 00:28:55 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/04/25 15:44:34 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp_address;
	t_list	*current_node;

	if (!lst || !del || !*lst)
		return ;
	current_node = *lst;
	while (current_node)
	{
		tmp_address = current_node->next;
		del(current_node->content);
		free(current_node);
		current_node = tmp_address;
	}
	*lst = NULL;
}

// #include <stdio.h>

// void	del_content(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	t_list	*head;

// 	head = NULL;
// 	ft_lstadd_back(&head, ft_lstnew(ft_strdup("String 1")));
// 	ft_lstadd_back(&head, ft_lstnew(ft_strdup("String 2")));
// 	ft_lstadd_back(&head, ft_lstnew(ft_strdup("String 3")));
// 	printf("%s\n", (char *)(head->next)->content);
// 	ft_lstclear(&head, del_content);
// 	printf("%d\n", head == NULL);
// 	return (0);
// }

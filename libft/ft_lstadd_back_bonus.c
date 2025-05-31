/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:54:38 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/04/24 16:11:52 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp_lst;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp_lst = *lst;
	while (tmp_lst->next)
		tmp_lst = tmp_lst->next;
	tmp_lst->next = new;
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*current;

// 	head = NULL;
// 	t_list *node1, *node2, *node3;
// 	node1 = ft_lstnew("Node 1 (First)");
// 	if (!node1)
// 		return (1);
// 	ft_lstadd_back(&head, node1);
// 	printf("List after adding node 1:\n");
// 	current = head;
// 	while (current != NULL)
// 	{
// 		printf("  - %s\n", (char *)current->content);
// 		current = current->next;
// 	}
// 	printf("Size: %d\n\n", ft_lstsize(head));
// 	node2 = ft_lstnew("Node 2 (Second)");
// 	node3 = ft_lstnew("Node 3 (Third)");
// 	ft_lstadd_back(&head, node2);
// 	ft_lstadd_back(&head, node3);
// 	printf("List after adding nodes 2 and 3:\n");
// 	current = head;
// 	while (current != NULL)
// 	{
// 		printf("  - %s\n", (char *)current->content);
// 		current = current->next;
// 	}
// 	printf("Size: %d\n\n", ft_lstsize(head));
// 	return (0);
// }

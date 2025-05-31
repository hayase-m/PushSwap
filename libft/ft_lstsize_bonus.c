/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:11:07 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/04/24 15:17:36 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	lst_size;

	lst_size = 0;
	while (lst)
	{
		lst = lst->next;
		lst_size++;
	}
	return (lst_size);
}

// #include <stdio.h>

// t_list	*ft_lstnew(void *content);
// void	ft_lstadd_front(t_list **lst, t_list *new);

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*node3;
// 	int		size;

// 	head = NULL;
// 	size = ft_lstsize(head);
// 	printf("%d\n", size);
// 	node1 = ft_lstnew("Node 1");
// 	node2 = ft_lstnew("Node 2");
// 	node3 = ft_lstnew("Node 3");
// 	ft_lstadd_front(&head, node1);
// 	ft_lstadd_front(&head, node2);
// 	ft_lstadd_front(&head, node3);
// 	size = ft_lstsize(head);
// 	printf("%d\n", size);
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

// void	ft_lstadd_front(t_list **lst, t_list *new)
// {
// 	if (!lst || !new)
// 		return ;
// 	new->next = *lst;
// 	*lst = new;
// }

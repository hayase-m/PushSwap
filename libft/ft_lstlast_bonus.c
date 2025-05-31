/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:55:08 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/04/24 20:55:09 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// #include <stdio.h>

// int  main(void)
// {
//  t_list  *head;
//  t_list  *last_node;

//  head = NULL;
//  t_list *node1, *node2, *node3;
//  last_node = ft_lstlast(head);
//  printf("Last node of empty list: %p\n", (void *)last_node);
//  head = ft_lstnew("Single Node");
//  last_node = ft_lstlast(head);
//  if (last_node)
//    printf("Last node of single list: %s\n", (char *)last_node->content);
//  head = NULL;
//  node1 = ft_lstnew("Node 1 (Last)");
//  node2 = ft_lstnew("Node 2 (Middle)");
//  node3 = ft_lstnew("Node 3 (First)");
//  ft_lstadd_front(&head, node1);
//  ft_lstadd_front(&head, node2);
//  ft_lstadd_front(&head, node3);
//  last_node = ft_lstlast(head);
//  if (last_node)
//    printf("Last node of multi-list: %s\n", (char *)last_node->content);
//  return (0);
// }

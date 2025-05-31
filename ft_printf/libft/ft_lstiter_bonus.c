/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:59:01 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/04/25 16:14:42 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// #include <stdio.h>

// void	print_content(void *content)
// {
// 	printf("%s\n", (char *)content);
// }

// int	main(void)
// {
// 	t_list	*head;

// 	head = NULL;
// 	ft_lstadd_back(&head, ft_lstnew("Apple"));
// 	ft_lstadd_back(&head, ft_lstnew("Banana"));
// 	ft_lstadd_back(&head, ft_lstnew("Cherry"));
// 	ft_lstiter(head, print_content);
// 	return (0);
// }

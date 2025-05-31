/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:15:40 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/04/25 16:14:51 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*new_lst;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	result = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_lst = ft_lstnew(new_content);
		if (!new_lst)
		{
			del(new_content);
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, new_lst);
		lst = lst->next;
	}
	return (result);
}

// #include <stdio.h>

// void	*map_duplicate_string(void *content)
// {
// 	if (!content)
// 		return (NULL);
// 	return (ft_strdup((char *)content));
// }

// void	del_simple_free(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	t_list	*original_list_head;
// 	t_list	*new_list_head;

// 	original_list_head = NULL;
// 	new_list_head = NULL;
// 	ft_lstadd_back(&original_list_head, ft_lstnew("First"));
// 	ft_lstadd_back(&original_list_head, ft_lstnew("Second"));
// 	ft_lstadd_back(&original_list_head, ft_lstnew("Third"));
// 	new_list_head = ft_lstmap(original_list_head, map_duplicate_string,
// 			del_simple_free);
// 	printf("%s\n", (char *)new_list_head->content);
// 	return (0);
// }

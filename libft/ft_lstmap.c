/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 21:40:54 by elewin            #+#    #+#             */
/*   Updated: 2026/03/31 13:18:52 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*new_list;
	t_list	*new_node;

	if (!lst)
		return (NULL);
	current = lst;
	new_list = NULL;
	while (current->next)
	{
		new_node = ft_lstnew(f(current->content));
		if (!new_node)
			ft_lstclear(&new_list, del);
		ft_lstadd_back(&new_list, new_node);
		current = current->next;
	}
	new_node = ft_lstnew(f(current->content));
	if (!new_node)
		ft_lstclear(&new_list, del);
	ft_lstadd_back(&new_list, new_node);
	return (new_list);
}

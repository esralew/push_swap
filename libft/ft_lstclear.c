/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:40:07 by elewin            #+#    #+#             */
/*   Updated: 2025/12/12 11:28:08 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (!lst)
		return ;
	if (*lst)
	{
		current = *lst;
		while (current->next)
		{
			next = current->next;
			ft_lstdelone(current, del);
			current = next;
		}
		ft_lstdelone(current, del);
		*lst = NULL;
	}
}

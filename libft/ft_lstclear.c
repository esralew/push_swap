/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:40:07 by elewin            #+#    #+#             */
/*   Updated: 2026/03/31 13:56:06 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !(*lst))
		return ;
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

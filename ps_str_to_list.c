/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_str_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:37:19 by elewin            #+#    #+#             */
/*   Updated: 2026/04/01 18:43:06 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*build_list(char **argv);

t_list	*str_to_lst(char **argv)
{
	t_list	*stack_a;

	stack_a = build_list(argv);
	if (!stack_a)
		return (NULL);
	return (stack_a);
}

static t_list	*build_list(char **argv)
{
	int		i;
	t_list	*stack_a;
	t_list	*node;
	int		*content;

	stack_a = NULL;
	i = 1;
	while (argv[i])
	{
		content = (int *)malloc(sizeof(int));
		if (!content)
			return (ft_lstclear(&stack_a, free), NULL);
		*content = ft_atoi(argv[i]);
		node = ft_lstnew(content);
		if (!node)
			return (ft_lstclear(&stack_a, free), free(content), NULL);
		ft_lstadd_back(&stack_a, node);
		i++;
	}
	return (stack_a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:37:57 by elewin            #+#    #+#             */
/*   Updated: 2026/04/03 17:48:47 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*push_swap(char **argv);
static t_list	*sort_elements(t_list *stack_a, t_list *stack_b);

int	main(int argc, char **argv)
{
	(void)argc;
	if (argc < 2)
		return (0);
	if (!check_input(argv) || !check_duplicate(argv))
		return (write(2, "Error\n", 6));
	if (!push_swap(argv))
		return (-1);
	return (0);
}

static t_list	*push_swap(char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = str_to_lst(argv);
	if (!stack_a)
		return (NULL);
	stack_b = NULL;
	if (ft_lstsize(stack_a) <= 5)
		return (sort_small(&stack_a, &stack_b), stack_a);
	push_3(&stack_a, &stack_b);
	sort_3_desc(&stack_b);
	if (!sort_elements(stack_a, stack_b))
		return (ft_lstclear(&stack_a, free), NULL);
	max_to_top(&stack_b);
	shift_all(&stack_a, &stack_b);
	return (ft_lstclear(&stack_a, free), stack_a);
}

static t_list	*sort_elements(t_list *stack_a, t_list *stack_b)
{
	t_list	*next_elem;
	t_list	*ops;

	while (1)
	{
		next_elem = get_next_elem(&stack_a, &stack_b);
		ops = get_ops(next_elem, &stack_a, &stack_b);
		if (!ops)
			return (NULL);
		perform_ops(ops, &stack_a, &stack_b);
		print_ops(ops);
		ft_lstclear(&ops, free);
		if (!stack_a)
			break ;
	}
	return (stack_b);
}

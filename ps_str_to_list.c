
// 42 HEADER

#include "push_swap.h"

static t_list *build_list(char **split_arr);
static void    free_split_arr(char **split_arr);

t_list   *str_to_list(char *input_str)
{
    char    **split_arr;
    t_list   *stack_a;

    split_arr = ft_split(input_str, ' ');
    if (!split_arr)
        return (NULL);
    stack_a = build_list(split_arr);
    free_split_arr(split_arr);
    if (!stack_a)
        return (NULL);
    return (stack_a);
}

/*
int get_n(char *input_str)
{
    int	i;
    int	n;  
    n = 0;
    i = 0;
    while (input_str[i])
    {
    	if (input_str[i] == ' ')
    		i++;
    	else
    	{
    		n++;
    		while (input_str[i] != ' ' && input_str[i])
    			i++;
    	}
    }
    return (n);
}
*/

static void    free_split_arr(char **split_arr)
{
    int i;

	i = 0;
	while (split_arr[i])
	{
		free(split_arr[i]);
		i++;
	}
	free(split_arr);
}

static t_list *build_list(char **split_arr)
{
    int i;
    t_list   *stack_a;
    t_list   *node;
    int *content;   

    stack_a = NULL;
    i = 0;
    while (split_arr[i])
    {
        content = (int *) malloc(sizeof(int));
        if (!content)
            return (ft_lstclear(&stack_a, free), NULL);
        *content = ft_atoi(split_arr[i]);
        node = ft_lstnew(content);
        if (!node)
            return (ft_lstclear(&stack_a, free), free(content), NULL);
        ft_lstadd_back(&stack_a, node);
        i++;
    }
    return (stack_a);
}
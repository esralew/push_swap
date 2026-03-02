
// 42 HEADER
#include "push_swap.h"

t_list   *str_to_list(char *input_str)
{
    char    **split_arr;
    int i;
    t_list   *stack_a;
    t_list   *node;
    int value;

    split_arr = ft_split(input_str, ' ');
        if (!split_arr)
            return (NULL);
    value = ft_atoi(split_arr[0]);
    stack_a = ft_lstnew(&value);
    i = 1;
    while (split_arr[i])
    {
        value = ft_atoi(split_arr[i]);
        node = ft_lstnew(&value);
        ft_lstadd_back(&stack_a, node);
        i++;
    }

    free_2d_arr(split_arr);
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

void    free_2d_arr(char **arr_2d)
{
    int i;

	i = 0;
	while (arr_2d[i])
	{
		free(arr_2d[i]);
		i++;
	}
	free(arr_2d);
}
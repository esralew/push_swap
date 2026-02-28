
// 42 HEADER
#include "push_swap.h"

int *str_to_arr(char *input_str, int *stack_a, int n)
{
    char    **split_arr;
    int i;

    split_arr = ft_split(input_str, ' ');
        if (!split_arr)
            return (NULL);
    i = 0;
    while (split_arr[i])
    {
        stack_a[i] = ft_atoi(split_arr[i]);
        i++;
    }
    free_2d_arr(split_arr, n);
    return (stack_a);
}

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

void    free_2d_arr(char **arr_2d, int n)
{
    int i;

	i = 0;
	while (i < n)
	{
		free(arr_2d[i]);
		i++;
	}
	free(arr_2d);
}

// 42 HEADER

#include "push_swap.h"
// REMOVE LATER WHEN FT_PRINTF IS INCLUDED IN LIBFT
#include <stdio.h>

void    print_ops(t_list *ops)
{
    t_list  *curr;

    curr = ops;
    while (curr->next)
    {
        printf("%s\n", (char *) curr->content);
        curr = curr->next;
    }
    printf("%s\n", (char *) curr->content);
}
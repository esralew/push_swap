
// 42 HEADER

#include "push_swap.h"
// REMOVE LATER WHEN FT_PRINTF IS INCLUDED IN LIBFT
#include <stdio.h>

int    print_ops(t_list *ops)
{
    t_list  *curr;
    int cnt;

    cnt = 0;
    curr = ops;
    while (1)
    {
        printf("%s\n", (char *) curr->content);
        cnt++;
        if (!(curr->next))
            break;
        curr = curr->next;
    }
    return (cnt);
}
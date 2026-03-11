
// 42 HEADER

#include "push_swap.h"

t_list  *find_max(t_list *stack)
{
    t_list *curr;
    t_list  *max;
    int max_val;

    curr = stack;
    max_val = *(int *) curr->content;
    while (1)
    {
        if (!(curr->next))
            break;
        if (*(int *) curr->content > max_val)
        {
            max_val = *(int *) curr->content;
            max = curr;
        }
        curr = curr->next;
    }
    return (max);
}
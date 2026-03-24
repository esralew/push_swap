
// 42 HEADER

#include "push_swap.h"

void    sort_3_desc(t_list **stack)
{
    int top;
    int mid;
    int bot;

    top = *(int *) (*stack)->content;    
    mid = *(int *) (*stack)->next->content;
    bot = *(int *) (*stack)->next->next->content;
    
    if (top > mid)
    {
        if (mid > bot)
            return;
        rrot(stack);
        if (top > bot)
            switcheroo(stack);
    }
    else
    {
        if (top > bot)
            return (switcheroo(stack));
        rot(stack);
        if (bot > mid)
            switcheroo(stack);
    }
}
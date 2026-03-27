
// 42 HEADER

#include "push_swap.h"

static void sort_desc(int top, int mid, int bot, t_list **stack);

void    sort_3_desc(t_list **stack)
{
    int top;
    int mid;
    int bot;

    top = *(int *) (*stack)->content;    
    mid = *(int *) (*stack)->next->content;
    bot = *(int *) (*stack)->next->next->content;
    sort_desc(top, mid, bot, stack);
    
}

static void sort_desc(int top, int mid, int bot, t_list **stack)
{
    if (top > mid)
        {
            if (mid > bot)
                return;
            rrot(stack);
            printf("rrb\n");
            if (top > bot)
            {
                switcheroo(stack);
                printf("sb\n");
            }
        }
        else
        {
            if (top > bot)
            {
                printf("sb\n");
                return (switcheroo(stack));
            }
            rot(stack);
            printf("rb\n");
            if (bot > mid)
            {
                switcheroo(stack);
                printf("sb\n");
            }
        }
}
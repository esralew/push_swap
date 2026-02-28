
// 42 HEADER

#include "push_swap.h"

void    ra(int *stack_a, int n)
{
    int temp;

    temp = stack_a[n - 1];
    stack_a[n - 1] = stack_a[0];
    stack_a[0] = temp;
}

void    rra(int *stack_a, int n)
{
    int temp;

    temp = stack_a[0];
    stack_a[0] = stack_a[n - 1];
    stack_a[n - 1] = temp;
}

void    pa(int *stack_a, int *stack_b, int n)
{
    
}
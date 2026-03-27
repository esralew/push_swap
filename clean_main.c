// 42 HEADER

#include <stdio.h>
#include "push_swap.h"

static void push_3(t_list **stack_a, t_list **stack_b);
static void shift_all(t_list **stack_a, t_list **stack_b);
static void max_to_top(t_list **stack_b);

int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;
    t_list  *ops;
    t_list  *next_elem;

    (void)argc;

    stack_a = str_to_list(argv[1]);
    if (!stack_a)
        return (-1); //return ERROR
    stack_b = NULL;

    push_3(&stack_a, &stack_b);
    sort_3_desc(&stack_b);

    while (1)
    {
        next_elem = get_next_elem(&stack_a, &stack_b);
        ops = get_ops(next_elem, &stack_a, &stack_b);
        perform_ops(ops, &stack_a, &stack_b);
        print_ops(ops);
        if (!stack_a)
            break;
    }
    max_to_top(&stack_b);
    shift_all(&stack_a, &stack_b);

    return (0);
}

//static void free_all()

static void push_3(t_list **stack_a, t_list **stack_b)
{
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    printf("pb\n");
    printf("pb\n");
    printf("pb\n");
}

static void shift_all(t_list **stack_a, t_list **stack_b)
{
    int n;

    n = ft_lstsize(*stack_b);
    while (n > 0)
    {
        pa(stack_a, stack_b);
        printf("pa\n");
        n--;
    }
}

static void max_to_top(t_list **stack_b)
{
    t_list  *max;
    int req_rot;
    int req_rrot;

    max = find_max(*stack_b);
    req_rot = get_req_rot(max, stack_b);
    req_rrot = get_req_rrot(max, stack_b);
    if (req_rot <= req_rrot)
    {
        while (req_rot--)
        {
            rot(stack_b);
            printf("rb\n");
        }
    }
    else
    {
        while (req_rrot--)
        {
            rrot(stack_b);
            printf("rrb\n");
        }
    }
}
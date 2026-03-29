
// 42 HEADER

#include <stdio.h>
#include "push_swap.h"

// static void print_stack(t_list *stack);
static void print_stacks(t_list *stack_a, t_list *stack_b);
static void push_3(t_list **stack_a, t_list **stack_b);
static void shift(t_list **stack_a, t_list **stack_b);
static void max_to_top(t_list **stack_b);

int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;
    t_list  *ops;
    t_list  *next_elem;

    (void)argc;

    stack_a = str_to_lst(argv);
    if (!stack_a)
        return (-1); //return ERROR
    stack_b = NULL;

    if (ft_lstsize(stack_a) <= 3)
    {
        sort_3_asc(&stack_a);
        return (0);
    }

    printf("INITIAL OPS: \n");

    push_3(&stack_a, &stack_b);
    sort_3_desc(&stack_b);

    print_stacks(stack_a, stack_b);
    // printf("\n");
    // printf("STACK A:\n");
    // print_stack(stack_a);
    // printf("\n");
    // printf("STACK B:\n");
    // print_stack(stack_b);
    printf("_____________________________________________________");
    printf("\n");

    while (1)
    {
        next_elem = get_next_elem(&stack_a, &stack_b);
        ops = get_ops(next_elem, &stack_a, &stack_b);
        perform_ops(ops, &stack_a, &stack_b);
        print_ops(ops);

        printf("\n");
        print_stacks(stack_a, stack_b);
        // printf("\n");
        // printf("STACK A:\n");
        // print_stack(stack_a);
        // printf("\n");
        // printf("STACK B:\n");
        // print_stack(stack_b);
        printf("_____________________________________________________");
        printf("\n");

        if (!stack_a)
            break;
    }


     max_to_top(&stack_b);
    shift(&stack_a, &stack_b);
    printf("\n");
    print_stacks(stack_a, stack_b);
    // printf("\n");
    // printf("STACK A:\n");
    // print_stack(stack_a);
    // printf("\n");
    // printf("STACK B:\n");
    // print_stack(stack_b);
    printf("_____________________________________________________");
    printf("\n");

    return (0);
}

//static void free_all()

// static void print_stack(t_list *stack)
// {
//     t_list  *curr;

//     if (!stack)
//         return;
//     curr = stack;
//     while (1)
//     {
//         printf("%d\n", *((int *) curr->content));
//         if (!(curr->next))
//             break;
//         curr = curr->next;
//     }
// }

static void push_3(t_list **stack_a, t_list **stack_b)
{
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    printf("pb\n");
    printf("pb\n");
    printf("pb\n");
}

static void shift(t_list **stack_a, t_list **stack_b)
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

static void print_stacks(t_list *stack_a, t_list *stack_b)
{
    t_list  *curr_a;
    t_list  *curr_b;
    int diff;

    if (!stack_a && !stack_b)
        return;
    curr_a = stack_a;
    curr_b = stack_b;
    printf("Stack A:     Stack B:\n\n");
    diff = ft_lstsize(stack_a) - ft_lstsize(stack_b);
    if (diff >= 0)
    {
        while(diff--)
        {
            printf("%d\n", *((int *) curr_a->content));
            curr_a = curr_a->next;
        }
    }
    else
    {
        while((diff++) < 0)
        {
            printf("           %d\n", *((int *) curr_b->content));
            curr_b = curr_b->next;
        }
    }
    if (!curr_a || !curr_b)
        return;
    while (1)
    {
        printf("%-5d      %d\n", *((int *) curr_a->content), *(int *) curr_b->content);
        if (!(curr_a->next))
            break;
        curr_a = curr_a->next;
        curr_b = curr_b->next;
    }
}
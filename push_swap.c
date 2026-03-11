
// 42 HEADER

#include <stdio.h>
#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;
    t_list  *current;
    // t_list  *ops;
    // storage *ops;
    // int op_count;
    int flag;
    int cost_a;

    (void)argc;

    stack_a = str_to_list(argv[1]);
    if (!stack_a)
        return (-1); //return ERROR
    stack_b = NULL;

    pb(&stack_a, &stack_b);
    pb(&stack_a, &stack_b);
    pb(&stack_a, &stack_b);
    pb(&stack_a, &stack_b);

    // op_count = 0;

    // ops = get_next_ops(stack_a, stack_b);
    // if (!ops)
    //    return (free_all(stack_a, stack_b), -1); //return ERROR
    // perform_ops(&stack_a, &stack_b, ops);
   // op_count += print_ops(ops);

   // sort_3(&stack_a);
   // shift_back(&stack_a, &stack_a);

    // BEFORE OPERATIONS
    printf("Stack A:\n");

    current = stack_a;
    while (current->next)
    {
        //    [Cost in B: %d]
        flag = 0;
        cost_a = calc_cost_a(current, &stack_a, &flag);
        printf("%d    [Cost moving to top: %d]\n", *((int *) current->content), cost_a); // calc_cost_b(current, &stack_b, flag, cost_a));
        current = current->next;
    }
    flag = 0;
    cost_a = calc_cost_a(current, &stack_a, &flag);
    printf("%d    [Cost moving to top: %d]\n", *((int *) current->content), cost_a); // calc_cost_b(current, &stack_b, flag, cost_a));

    // printf("Stack B:\n");

    // current = stack_b;
    // while (current->next)
    // {
    //     printf("%d\n", *((int *) current->content));
    //     current = current->next;
    // }
    // printf("%d\n", *((int *) current->content));

    // OPERATIONS //////////////////////////////////
    // pb(&stack_a, &stack_b);
    // pb(&stack_a, &stack_b);
    printf("required rotations for top element in stack a: %d\n", get_req_rot(stack_a, &stack_a));
    printf("required rev rotations for top element in stack a: %d\n", get_req_rrot(stack_a, &stack_a));
    printf("top element a: %d\n", *(int *) stack_a->content);
    printf("Successor of top element in a: %d\n", *(int *) (find_succ(stack_a, &stack_b)->content));
    printf("max of A: %d\n", *(int *) find_max(stack_a)->content);

    ////////////////////////////////////////////////
    printf("\n");

    // AFTER OPERATIONS
    printf("Stack A:\n");

    current = stack_a;
    while (current->next)
    {
        printf("%d\n", *((int *) current->content));
        current = current->next;
    }
    printf("%d\n", *((int *) current->content));

    printf("\n");

    printf("Stack B:\n");

    current = stack_b;
    while (current->next)
    {
        printf("%d\n", *((int *) current->content));
        current = current->next;
    }
    printf("%d\n", *((int *) current->content));

    return (0);
}

//static void free_all()
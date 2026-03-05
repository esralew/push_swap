
// 42 HEADER

#include <stdio.h>
#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;
    t_list  *current;
    t_list  *next_elem;
    storage *ops;
    int op_count;

    (void)argc;

    stack_a = str_to_list(argv[1]);
    if (!stack_a)
        return (-1); //return ERROR
    stack_b = NULL;

    op_count = 0;
    while (ft_lstsize(stack_a) > 3)
    {
        ops = get_next_ops(stack_a, stack_b);
        if (!ops)
            return (free_all(stack_a, stack_b), -1); //return ERROR
        perform_ops(&stack_a, &stack_b, ops);
        op_count += print_ops(ops);
    }

    sort_3(&stack_a);
    shift_back(&stack_a, &stack_a);

    // BEFORE OPERATIONS
    printf("Stack A:\n");

    current = stack_a;
    while (current->next)
    {
        printf("%d\n", *((int *) current->content));
        current = current->next;
    }
    printf("%d\n", *((int *) current->content));

    // printf("Stack B:\n");

    // current = stack_b;
    // while (current->next)
    // {
    //     printf("%d\n", *((int *) current->content));
    //     current = current->next;
    // }
    // printf("%d\n", *((int *) current->content));

    // OPERATIONS //////////////////////////////////
    pb(&stack_a, &stack_b);
    pb(&stack_a, &stack_b);
    pb(&stack_a, &stack_b);
    rotrot(&stack_a, &stack_b);
    //pa(&stack_a, &stack_b);

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

// 42 HEADER

#include <stdio.h>
#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;
    t_list  *current;

    (void)argc;

    stack_a = str_to_list(argv[1]);
    if (!stack_a)
        return (-1); //return ERROR
    stack_b = NULL;

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
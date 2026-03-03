
// 42 HEADER

#include <stdio.h>
#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list *stack_a;
    //t_list *stack_b;
    t_list  *current;

    (void)argc;

    stack_a = str_to_list(argv[1]);
    if (!stack_a)
        return (-1); //return ERROR
    //stack_b = NULL;

    current = stack_a;
    while (current->next)
    {
        printf("%d\n", *((int *) current->content));
        current = current->next;
    }
    printf("%d\n", *((int *) current->content));

    ra(&stack_a);
    ra(&stack_a);
    ra(&stack_a);

    rra(&stack_a);
    rra(&stack_a);
    //rra(&stack_a);
    

    printf("\n");

    current = stack_a;
    while (current->next)
    {
        printf("%d\n", *((int *) current->content));
        current = current->next;
    }
    printf("%d\n", *((int *) current->content));
    return (0);
}
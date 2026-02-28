
// 42 HEADER
#include <stdio.h>
#include "push_swap.h"

int main(int argc, char **argv)
{
    int *stack_a;
    int *stack_b;
    int i;
    int n;

    (void)argc;
    n = get_n(argv[1]);
    printf("number of elements: %d\n", n);

    stack_a = (int *) malloc(n * sizeof(int));
    if (!stack_a)
        return (-1); //return ERROR
    stack_b = (int *) malloc(n * sizeof(int));
    if (!stack_b)
        return (-1); //return ERROR

    str_to_arr(argv[1], stack_a, n);
    if (!stack_a)
        return (-1); //return ERROR
    
        i = 0;
    while (i < n)
    {
        printf("%d\n", stack_a[i]);
        i++;
    }
    return (0);
}
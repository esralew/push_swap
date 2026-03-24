
// 42 HEADER

#include <stdio.h>
#include "push_swap.h"

static void print_stack(t_list *stack);

int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;
    t_list  *current;
    //t_list  *ops;
    t_list  *ops_a;
    t_list  *ops_b;
    int flag;
    int cost_a;

    (void)argc;

    stack_a = str_to_list(argv[1]);
    if (!stack_a)
        return (-1); //return ERROR
    stack_b = str_to_list(argv[2]);

    // ops = get_ops(stack_a, stack_b);
    // if (!ops)
    //    return (free_all(stack_a, stack_b), -1); //return ERROR
    // op_cnt = perform_ops(&stack_a, &stack_b, ops);

    // push_3(&stack_a, &stack_b);
   // sort_3_desc(&stack_b);

   // shift_back(&stack_a, &stack_a);
    // while (stack_a)
    // {
        // ops = get_ops(stack_a, stack_b);
        // if (!ops)
        //    return (free_all(stack_a, stack_b), -1); //return ERROR
        // op_cnt += perform_ops(&stack_a, &stack_b, ops);
        // print_ops(ops);

    // }
    // printf("Number of operations: %d\n", op_cnt);
    
    // BEFORE OPERATIONS
    printf("Stack A:\n");

    current = stack_a;
    while (current->next)
    {
        flag = 0;
        cost_a = calc_cost_a(current, &stack_a, &flag);
        printf("%-6d  [Cost moving to top: %d]    [Cost in B: %d]   [Total Cost: %d]\n", *((int *) current->content), cost_a, calc_cost_b(current, &stack_b, flag, cost_a), calc_cost(current, &stack_a, &stack_b));
        current = current->next;
    }
    flag = 0;
    cost_a = calc_cost_a(current, &stack_a, &flag);
    printf("%-6d  [Cost moving to top: %d]    [Cost in B: %d]   [Total Cost: %d]\n", *((int *) current->content), cost_a, calc_cost_b(current, &stack_b, flag, cost_a), calc_cost(current, &stack_a, &stack_b));

    printf("\n");

    printf("Stack B:\n");

    print_stack(stack_b);
    
    // OPERATIONS //////////////////////////////////

    // printf("required rotations for top element in stack a: %d\n", get_req_rot(stack_a, &stack_a));
    // printf("required rev rotations for top element in stack a: %d\n", get_req_rrot(stack_a, &stack_a));
    printf("top element a: %d\n", *(int *) stack_a->content);
    printf("Successor of top element in a: %d\n", *(int *) (find_succ(stack_a, &stack_b)->content));
    printf("max of A: %d\n", *(int *) find_max(stack_a)->content);
    printf("Next element to move: %d\n", *(int *) get_next_elem(&stack_a, &stack_b)->content);
    flag = 0;
    ops_a = get_ops_a(get_next_elem(&stack_a, &stack_b), &stack_a, &flag);
    ops_b = get_ops_b(get_next_elem(&stack_a, &stack_b), &stack_a, &stack_b, flag);
    //ops = get_ops(get_next_elem(&stack_a, &stack_b), &stack_a, &stack_b);


    printf("\n");

    printf("Operations required to move 'next element to move (in a)': \n");

    print_ops(ops_a);

    printf("\n");

    printf("Operations required to move 'next element to move (in b)': \n");

    print_ops(ops_b);

    printf("\n");

    printf("OVERALL Operations required to move next element: \n");

    //print_ops(ops);

    ////////////////////////////////////////////////
    printf("\n");

    // AFTER OPERATIONS
    printf("Stack A:\n");

    print_stack(stack_a);

    printf("Stack B:\n");

   print_stack(stack_b);

   sort_3_desc(&stack_b);
   printf("Sorted stack:\n");
   print_stack(stack_b);

    return (0);
}

//static void free_all()

static void print_stack(t_list *stack)
{
    t_list  *curr;

    curr = stack;
    while (curr->next)
    {
        printf("%d\n", *((int *) curr->content));
        curr = curr->next;
    }
    printf("%d\n\n", *((int *) curr->content));
}
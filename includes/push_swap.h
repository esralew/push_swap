
// 42 HEADER

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

t_list   *str_to_list(char *input_str);
void    rot(t_list **stack);
void    rrot(t_list **stack);
void    rotrot(t_list **stack_a, t_list **stack_b);
void    rrotrrot(t_list **stack_a, t_list **stack_b);
void    pa(t_list **stack_a, t_list **stack_b);
void    pb(t_list **stack_a, t_list **stack_b);
t_list *get_next_ops(t_list **stack_a, t_list **stack_b);
t_list  *find_succ(t_list *node, t_list **stack_b);
int calc_cost(t_list *node, t_list **stack_a, t_list **stack_b);
int calc_cost_a(t_list *node, t_list **stack_a, int *flag);
int calc_cost_b(t_list *node, t_list **stack_b, int flag, int cost_a);
int get_req_rot(t_list *node, t_list **stack);
int get_req_rrot(t_list *node, t_list **stack);
int calc_cost_sync(int flag,int cost_a,int req_rot_b,int req_rrot_b);
int calc_cost_opp(int flag, int req_rot_b,int req_rrot_b);
int abs(int x);
t_list  *find_max(t_list *stack);
t_list  *get_next_elem(t_list **stack_a, t_list **stack_b);

#endif
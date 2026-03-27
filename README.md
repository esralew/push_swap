*This project has been created as part of the 42 curriculum by elewin.*

**** WORK IN PROGRESS ****

### Table of Contents

+ [Description](#description)
+ [Instructions](#instructions)
+ [Resources](#resources)
+ [How the implemented algorithm works](#how-the-implemented-algorithm-works)
+ [Alternative algorithms](#alternative-algorithms)
+ [General Learnings](#general-learnings)

### Description

The project push_swap introduces the concept of time complexity in sorting algorithms. The objective is to sort a set of random unique integers in ascending order which are located in a stack data structure. Two stacks a and b can be used for this, where stack a initially contains all the values, whereas stack b is empty. 
The goal is to use the smallest possible number of operations to sort the stack a. The actual internal operations performed (like e.g. comparing two values) are not relevant.

**Allowed operations**:
+ **swap a**: swap the first 2 elements at the top of stack a.
Do nothing if there is only one element or none.
+ **swap b**: swap the first 2 elements at the top of stack b.
Do nothing if there is only one element or none.
+ **swap swap**: swap a and swap b at the same time\ 
<br>

+ **push a**: Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
+ **push b**: Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
<br>

+ **rotate a**: Shift up all elements of stack a by 1.
The first element becomes the last one.
+ **rotate b**: Shift up all elements of stack b by 1.
The first element becomes the last one.
+ **rotate rotate**: rotate a and rotate b at the same time
<br>

+ **reverse rotate a**: hift down all elements of stack a by 1.
The last element becomes the first one.
+ **reverse rotate b**: Shift down all elements of stack b by 1.
The last element becomes the first one.
+ **reverse rotate rotate**: rra and rrb at the same time

### Instructions

### Resources

+ Space complexity: https://www.datacamp.com/tutorial/space-complexity?dc_referrer=https%3A%2F%2Fwww.google.com%2F
+ Mechanical Turk: https://en.wikipedia.org/wiki/Mechanical_Turk
+ 

### How the implemented algorithm works

### Alternative algorithms

### General Learnings

#### exit()

+ The **void exit(int status)** function is included in stdlib.h and terminates the program/process immediately, sending the status information to the parent process. The macros EXIT_FAILURE and EXIT_SUCCESS for the status are predefined in stdlib.h and do not need to be specified (usually they expand to 0 and 1). Using them instead of 0 ad 1 is better practice for better portability. 
#### Structs in C

```
typedef struct s_list
{
	void            *content;
	struct s_list   *next;
}                         t_list;
```

This is a combination of a **struct declaration** (struct s_list { ... }), which creates a new type called 'struct s_list' with the fields 'content' and 'next' AND a **typedef instruction** (which could also be spelled 'typedef struct s_list t_list).

The struct t_list is a block of memory that contains the fields specified in the struct. 

```
t_list *node;

# pointer to the t_list struct called node
t_list *adress = node;

# a copy of the whole struct node (node is a pointer and we dereference it here)
t_list temp = *node;

# two identical versions of accessing the content object from the node struct
void *value = *(node).content;
void *value = node->content;

```


#### Heap Sort

+ time complexity is **O(nlogn)**
+ additional memory requirements: **in-place** (algorithm doesn't need any memory on top of the memory the input data structure already uses)
+ **stable sorting algorithm** (if any key-value pairs share the same key, they never switch places after the algorithm was performed, but they stay in the same order as they were before)
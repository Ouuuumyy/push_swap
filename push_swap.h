#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct s_node
{
    int value;
    struct s_node *next;
}               s_node;

//libft.c
int ft_strlen(char *str);
int ft_atoi(char *str);
int is_number(char *str);
char	*ft_strchr(const char *s, int c);

//split.c
char	**ft_split(char *s, char c);

//stack_utils
int check_dup(s_node **stack, int value);
void push(s_node **stack, int value);
void print_stack(s_node **stack);

//stack_utils
int already_sorted_stack(s_node **stack_a);
void sort_reversed_stack(s_node **stack, s_node **stack_b);
int reversed_sorted_array(s_node **stack);
void print_stack(s_node **stack);

//parsing
void parsing(s_node **stack,char **av);
void print_error(char *str);

//stack_operations
void swap_elements(s_node **stack, char stack_name);
void swap_both_stacks(s_node **stack_a, s_node **stack_b);
void push_to_stack(s_node **stack_a, s_node **stack_b, char direction);
void rotate_stack(s_node **stack, char stack_name);
void rotate_both_stacks(s_node **stack_a, s_node **stack_b);
void reverse_rotate_stack(s_node **stack, char stack_name);
void rr_both_stacks(s_node **stack_a, s_node **stack_b);

//sorting_small_stacks
void sort_two(s_node **stack);
void sort_three(s_node **stack);
void sort_four(s_node **stack_a, s_node **stack_b);
void sort_five(s_node **stack_a, s_node **Stack_b);
void sort_small_stacks(s_node **stack_a, s_node **stack_b);
s_node *min_node(s_node **stack);

//stack_to_array
int stack_size(s_node *stack);
int *extract_array(s_node **stack, int size);
void sort_array(int *arr, int size);

//sorting_large_stacks
int set_range(int size);
int *extract_sorted_array(s_node **stack, int size);
void sort_stack_b_by_array(s_node **stack_a, s_node **stack_b, int size);
int find_largest_index(s_node **stack);
void move_largest_to_top(s_node **stack, char stack_name);
void sort_large_stacks(s_node **stack_a, s_node **stack_b);

//push_swap.c

#endif
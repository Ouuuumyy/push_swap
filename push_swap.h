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

//stack_func
int check_dup(s_node **stack, int value);
void push(s_node **stack, int value);
void pop(s_node **stack, s_node *node);
void print_stack(s_node **stack);

//parsing
void parsing(s_node **stack,char **av);

//stack_operations
void swap_elements(s_node **stack);
void swap_both_stacks(s_node **stack_a, s_node **stack_b);
void push_two_elements(s_node **stack_a, s_node **stack_b);
void rotate_stack(s_node **stack);
void rotate_both_stacks(s_node **stack_a, s_node **stack_b);
void reverse_rotate_stack(s_node **stack);
void rr_both_stacks(s_node **stack_a, s_node **stack_b);

//sorting_few_elements
void sort_three(s_node **stack);

//push_swap.c

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 04:56:07 by oukadir           #+#    #+#             */
/*   Updated: 2025/03/04 21:49:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void swap_elements(s_node **stack, char stack_name)
{
    if(!*stack || !(*stack)->next)
        return;
    s_node *a;
    s_node *b;

    a = *stack;
    b = a->next;
    a->next = b->next;
    b->next = a;
    *stack = b;
    printf("s%c\n", stack_name);
}
void swap_both_stacks(s_node **stack_a, s_node **stack_b)
{
    swap_elements(stack_a, 'a');
    swap_elements(stack_b, 'b');
    printf("ss\n");
}

void push_to_stack(s_node **stack_a, s_node **stack_b, char direction)
{
    s_node *first_node;
    
    if(!*stack_a)
        return;
    first_node = *stack_a;
    *stack_a = first_node->next;
    first_node->next = *stack_b;
    *stack_b = first_node;
    printf("p%c\n", direction);
}

void rotate_stack(s_node **stack, char stack_name)
{
    s_node *first_node;
    s_node *temp;
    
    if(!*stack || !(*stack)->next)
        return;
    first_node = *stack;
    *stack = (*stack)->next;
    temp = *stack;
    while(temp->next)
    {
        temp = temp->next;
    }
    temp->next = first_node;
    first_node->next = NULL;
    printf("r%c\n", stack_name);
}

void rotate_both_stacks(s_node **stack_a, s_node **stack_b)
{
    rotate_stack(stack_a, 'a');
    rotate_stack(stack_b, 'b');
    printf("rr\n");
}

void reverse_rotate_stack(s_node **stack, char stack_name)
{
    s_node *first_node;
    s_node *last_node;
    s_node *temp;
    
    if(!*stack || !(*stack)->next)
        return;
    first_node = *stack;
    temp = *stack;
    while(temp->next)
    {
        if(!(temp->next)->next)
            break;
        temp = temp->next;
    }
    last_node = temp->next;
    temp->next = NULL;
    last_node->next = first_node;
    *stack = last_node;
    printf("rr%c\n", stack_name);
}
void rr_both_stacks(s_node **stack_a, s_node **stack_b)
{
    reverse_rotate_stack(stack_a, 'a');
    reverse_rotate_stack(stack_b, 'b');
    printf("rrr\n");
}
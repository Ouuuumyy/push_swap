/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 04:56:07 by oukadir           #+#    #+#             */
/*   Updated: 2025/02/19 02:53:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void swap_elements(s_node **stack)
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
}
void swap_both_stacks(s_node **stack_a, s_node **stack_b)
{
    swap_elements(stack_a);
    swap_elements(stack_b);
}

void push_to_stack(s_node **stack_a, s_node **stack_b)
{
    s_node *first_node;
    
    if(!*stack_a)
        return;
    first_node = *stack_a;
    *stack_a = first_node->next;
    first_node->next = *stack_b;
    *stack_b = first_node;
}

void rotate_stack(s_node **stack)
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
}

void rotate_both_stacks(s_node **stack_a, s_node **stack_b)
{
    rotate_stack(stack_a);
    rotate_stack(stack_b);
}

void reverse_rotate_stack(s_node **stack)
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
}
void rr_both_stacks(s_node **stack_a, s_node **stack_b)
{
    reverse_rotate_stack(stack_a);
    reverse_rotate_stack(stack_b);
}
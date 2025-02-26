/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 01:18:44 by oukadir           #+#    #+#             */
/*   Updated: 2025/02/20 23:47:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(s_node **stack)
{
    s_node *temp;

    if (!*stack)
    {
        printf("empty stack");
        return;
    }
    temp = *stack;
    while (temp)
    {
        printf("%d\n", temp->value);
        temp = temp->next;
    }
}
int check_dup(s_node **stack, int value)
{
    s_node *temp;

    temp = *stack;
    while(temp)
    {
        if(temp->value == value)
            return 1;
        temp = temp->next;
    }
    return 0;
}
void push(s_node **stack, int value)
{
    s_node *node;
    node = malloc(sizeof(s_node));
    if(!node)
        return;
    node->next = *stack;
    node->value = value;
    *stack = node;
}

void pop(s_node **stack, s_node *node)
{
    s_node *temp;

    temp = *stack;
    *stack = temp->next;
    free(temp);
}


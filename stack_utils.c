/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 01:18:44 by oukadir           #+#    #+#             */
/*   Updated: 2025/03/05 00:12:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(s_node **stack)
{
    s_node *temp;

    // if (!*stack)
    // {
    //     printf("empty stack");
    //     return;
    // }
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
    s_node *temp;
    temp = *stack;
    
    if(!*stack)
        *stack = node;
    else
    {
        while(temp->next)
            temp = temp->next;
        temp->next = node;
    }
    node->value = value;
    node->next = NULL;
}

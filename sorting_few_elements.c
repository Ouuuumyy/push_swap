/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_few_elements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukadir <oukadir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 02:11:06 by oukadir           #+#    #+#             */
/*   Updated: 2025/02/16 01:47:08 by oukadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_two(s_node **stack)
{
    if ((*stack)->value > ((*stack)->next)->value)
        swap_elements(stack);
}

s_node *min_node(s_node **stack)
{
    s_node *min;
    s_node *temp;

    if (!stack || !*stack)
        return NULL;
    min = *stack;
    temp = (*stack)->next;
    while (temp)
    {
        if (temp->value < min->value)
            min = temp;
        temp = temp->next;
    }
    return min;
}
s_node *max_node(s_node **stack)
{
    s_node *max;
    s_node *temp;

    if (!stack || !*stack)
        return NULL;
    max = *stack;
    temp = (*stack)->next;
    while (temp)
    {
        if (temp->value > max->value)
            max = temp;
        temp = temp->next;
    }
    return max;
}

void sort_three(s_node **stack)
{
    s_node *max;
    s_node *min;
    s_node *first;
    s_node *mid;
    s_node *third;

    max = max_node(stack);
    min = min_node(stack);
    first = *stack;
    mid = first->next;
    third = mid->next;
    if (first->value == max->value)
    {
        rotate_stack(stack);
        print_stack(stack);
        printf("--------------");
    }
    if (mid->value == min->value)
    {
        reverse_rotate_stack(stack);
        print_stack(stack);
        printf("--------------");
    }
    if (first->value > mid->value)
    {
        swap_elements(stack);
        print_stack(stack);
        printf("--------------");
    }
    if (third->value == min->value)
    {
        rotate_stack(stack);
        print_stack(stack);
        printf("--------------");
    }
}
// int main()
// {
//     int tab[3] = {23, 100, 3};

//     int min = find_max(tab);
//     printf("%d\n", min);
//     return 0;
// }
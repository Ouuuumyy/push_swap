
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
    s_node *min;
    s_node *first;
    s_node *mid;
    s_node *third;

    min = min_node(stack);
    first = *stack;
    mid = first->next;
    third = mid->next;
    if(first->value < mid->value && mid->value < third->value)
        return;
    else if(first->value == min->value)
        sort_two(&(*stack)->next);
    else if(mid->value == min->value)
    {
        rotate_stack(stack);
        sort_two(&(*stack)->next);
    }
    else if(third->value == min->value)
    {
        reverse_rotate_stack(stack);
        sort_two(&(*stack)->next);
    }
}

void sort_four(s_node **stack_a, s_node **stack_b)
{
    s_node *min;

    min = min_node(stack_a);
    if((*stack_a)->next == min)
        swap_elements(stack_a);
    else if((*stack_a)->next->next == min)
    {
        rotate_stack(stack_a);
        rotate_stack(stack_a);
    }
    else if((*stack_a)->next->next->next == min)
        reverse_rotate_stack(stack_a);
    push_to_stack(stack_a, stack_b);
    sort_three(stack_a);
    push_to_stack(stack_b, stack_a);
}
void sort_five(s_node **stack_a, s_node **stack_b)
{
    s_node *min;

    min = min_node(stack_a);
    if((*stack_a)->next == min)
        swap_elements(stack_a);
    else if((*stack_a)->next->next == min)
    {
        rotate_stack(stack_a);
        rotate_stack(stack_a);
    }
    else if((*stack_a)->next->next->next == min)
    {
        reverse_rotate_stack(stack_a);
        reverse_rotate_stack(stack_a);
    }
    else if((*stack_a)->next->next->next->next == min)
        reverse_rotate_stack(stack_a);
    push_to_stack(stack_a, stack_b);
    sort_four(stack_a, stack_b);
    push_to_stack(stack_b, stack_a);
}

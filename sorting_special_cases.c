#include "push_swap.h"

int already_sorted_stack(s_node **stack_a)
{
    int size;
    int count;
    s_node *temp;

    size = stack_size(*stack_a);
    count = 0;
    temp = *stack_a;
    while(temp && temp->next)
    {
        if(temp->value < (temp->next)->value)
        {
            temp = temp->next;
            count++;
        }
        else
            break;
    }
    if(count == size - 1)
        return 1;
    else
        return 0;
}
int reversed_sorted_array(s_node **stack)
{
    int size;
    int *tab;
    int i;
    
    size = stack_size(*stack);
    i = size - 1;
    tab = extract_array(stack,size);
    while(i > 0 && tab[i] < tab[i - 1])
        i--;
    if(i == 0)
        return 1;
    else   
        return 0;
}

void sort_reversed_stack(s_node **stack_a, s_node **stack_b)
{
    while(*stack_a)
    {
        reverse_rotate_stack(stack_a, 'a');
        push_to_stack(stack_a, stack_b, 'b');
    }
    while(*stack_b)
        push_to_stack(stack_b,stack_a, 'a');
}

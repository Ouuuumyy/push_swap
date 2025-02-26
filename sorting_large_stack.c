#include "push_swap.h"

int set_range(int size)
{
    int range;
    if(size > 5 && size <= 20)
        range = 3;
    else if(size >= 21 && size <= 100)
        range = 15;
    else if(size >= 101 && size <= 500)
        range = 35;
    else
        range = 45;
    return range;
}

int *extract_sorted_array(s_node **stack, int size)
{
    int *arr = extract_array(stack, size);
    if(!arr)
        return NULL;
    sort_array(arr, size);
    return arr;
}


void sort_stack_b_by_array(s_node **stack_a, s_node **stack_b, int size)
{
    int start;
    int end;
    int *arr;

    start = 0;
    end = set_range(size) - 1;
    arr = extract_sorted_array(stack_a, size);
    if(!arr)
        return;
    while(*stack_a)
    {
        if (start >= size || end >= size)
            break;
        if((*stack_a)->value >= arr[start] && (*stack_a)->value <= arr[end])
        {
            push_to_stack(stack_a, stack_b);
            start++;
            end++;
        }
        else if((*stack_a)->value < arr[start])
        {
            push_to_stack(stack_a, stack_b);
            rotate_stack(stack_b);
            start++;
            end++;
        }
        else
            rotate_stack(stack_a);
    }
    free (arr);
}

int find_largest_index(s_node **stack)
{
    int max_index;
    int max_value;
    int i;
    s_node *temp;

    i = 0;
    max_index = 0;
    temp = *stack;
    max_value = temp->value;
    while(temp)
    {
        if(temp->value > max_value)
        {
            max_value = temp->value;
            max_index = i;
        }
        temp = temp->next;
        i++;
    }
    return max_index;
}

void move_largest_to_top(s_node **stack)
{
    int size;
    int largest_index;

    size = stack_size(*stack);
    largest_index = find_largest_index(stack);
    if(largest_index <= size / 2)
    {
        while(largest_index > 0)
        {
            rotate_stack(stack);
            largest_index--;
        }
    }
    else
    {
        while(largest_index < size)
        {
            reverse_rotate_stack(stack);
            largest_index++;
        }
    }
}

void sort_large_stacks(s_node **stack_a, s_node **stack_b)
{
    int size;

    size = stack_size(*stack_a);
    sort_stack_b_by_array(stack_a, stack_b, size);
    while(*stack_b)
    {
        move_largest_to_top(stack_b);
        push_to_stack(stack_b, stack_a);
    }
}

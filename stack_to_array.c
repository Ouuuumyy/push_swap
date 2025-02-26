#include "push_swap.h"

int stack_size(s_node *stack)
{
    int size;
    s_node *temp;

    size = 0;
    temp = stack;
    while(temp)
    {
        size++;
        temp = temp->next;
    }
    return size;
}
int *extract_array(s_node **stack, int size)
{
    int *tab;
    s_node *temp;
    int i;

    i = 0;
    temp = *stack;
    tab = malloc(sizeof(int) * size);
    if(!tab)
        return NULL;
    while(temp)
    {
        tab[i] = temp->value;
        temp = temp->next;
        i++;
    }
    return tab;
}

int partition(int *arr, int low, int high)
{
    int i;
    int j;
    int pivot;
    int temp;

    i = low - 1;
    j = low;
    pivot = arr[high];
    while(j < high)
    {
        if(arr[j] < pivot)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        j++;
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return(i + 1);
}

void quick_sort(int *arr, int low, int high)
{
    int pivot_index;

    if(low < high)
    {
        pivot_index = partition(arr, low, high);
        quick_sort(arr, low, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, high);
    }
}

void sort_array(int *arr, int size)
{
    quick_sort(arr, 0, size -  1);
}



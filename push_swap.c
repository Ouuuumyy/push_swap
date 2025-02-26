/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:35:43 by oukadir           #+#    #+#             */
/*   Updated: 2025/02/25 15:06:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int ac, char **av)
{
    (void)ac;
    int i;
    int num;
    i = 1;
    num = 0;
 
    s_node *stack_a = NULL;
    s_node *stack_b = NULL;
    
    if(ac == 1)
    {
        printf("no numbers entenred\n");
        return 1;
    }
    parsing(&stack_a, av);
    print_stack(&stack_a);
    int size = stack_size(stack_a);
    printf("stack size is %d \n", size);
    //int *tab = extract_sorted_array(&stack_a, size);
  
    // int j = 0;
    // printf("--------------------------\n");
    // while(j < size)
    // {
    //     printf("[%d] : %d\n", j, tab[j]);
    //     j++;
    // }
    sort_stack_b_by_array(&stack_a, &stack_b, size);
    print_stack(&stack_b);

    printf("stack a ------------------------->\n");
    print_stack(&stack_a);

    return 0;
}


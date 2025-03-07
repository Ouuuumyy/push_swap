/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:35:43 by oukadir           #+#    #+#             */
/*   Updated: 2025/03/07 01:02:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int ac, char **av)
{
    (void)ac; 
    s_node *stack_a = NULL;
    s_node *stack_b = NULL;
    if(ac < 2)
    {
        print_error("Error\n");
        
    }
    parsing(&stack_a, av);
    int size = stack_size(stack_a);
    if(size <= 5)
     {
        sort_small_stacks(&stack_a, &stack_b);
        return 0;       
     }
     if(already_sorted_stack(&stack_a) )
     {
         return 0;       
     }
     if(reversed_sorted_array(&stack_a))
     {
         sort_reversed_stack(&stack_a, &stack_b);
         print_stack(&stack_a);
         return 0;
     }
    if(size > 5)
        sort_large_stacks(&stack_a, &stack_b);
 
    return 0;
}


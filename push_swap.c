/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukadir <oukadir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:35:43 by oukadir           #+#    #+#             */
/*   Updated: 2025/02/16 01:19:57 by oukadir          ###   ########.fr       */
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
    if(ac == 1)
    {
        printf("no numbers entenred\n");
        return 1;
    }
    parsing(&stack_a, av);
    print_stack(&stack_a);
    sort_three(&stack_a);
    print_stack(&stack_a);
    return 0;
}
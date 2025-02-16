/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukadir <oukadir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:05:56 by oukadir           #+#    #+#             */
/*   Updated: 2025/02/12 04:52:14 by oukadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_error(char *str)
{
    write(2, str, ft_strlen(str));
    exit(1);
}

void validate_input(s_node **stack, char *s)
{
    int num;
    num = 0;

    if (!is_number(s))
        print_error("input is not a number\n");
    num = ft_atoi(s);
    if (check_dup(stack, num))
        print_error("a number is duplicated\n");
    push(stack, num);
}
void parsing(s_node **stack,char **av)
{
    int i;
    int j;
    char **temp;
    temp = NULL;
    i = 1;
    j = 0;

    while (av[i])
    {
        if(ft_strchr(av[i], ' '))
        {
            temp = ft_split(av[i], ' ');
            while(temp[j])
            {
                validate_input(stack, temp[j]);
                free(temp[j]);
                j++;
            }
            free(temp);
        }
        else
            validate_input(stack, av[i]);
        i++;
    }
}
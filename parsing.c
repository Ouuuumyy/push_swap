/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:05:56 by oukadir           #+#    #+#             */
/*   Updated: 2025/03/05 00:09:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_error(char *str)
{
    write(2, str, ft_strlen(str));
    exit(1);
}

int is_only_spaces(char *s)
{
    int i;

    i = 0;
    while(s[i])
    {
        if(s[i] != ' ')
            return 0;
        i++;
    }
    return 1;
}
void validate_input(s_node **stack, char *s)
{
    int num;
    num = 0;
    if(ft_strlen(s) == 0 || is_only_spaces(s))
        print_error("Error\n");
    if (!is_number(s))
        print_error("Error\n");
    num = ft_atoi(s);
    if (check_dup(stack, num))
        print_error("Error\n");
    push(stack, num);
}

void check_temp(char **temp, s_node **stack)
{
    int j;

    j = 0;
    if(!temp || !temp[0])
            {
                free(temp);
                print_error("Error\n");
            }
            while(temp[j])
            {
                validate_input(stack, temp[j]);
                free(temp[j]);
                j++;
            }
            free(temp);
}
void parsing(s_node **stack, char **av)
{
    int i;
    char **temp;
    temp = NULL;
    i = 1;

    // if(ac < 2)
    // {
    //     print_error("Error\n");
    // }
    while (av[i])
    {
        if(ft_strchr(av[i], ' '))
        {
            temp = ft_split(av[i], ' ');
            check_temp(temp, stack);
        }
        else
            validate_input(stack, av[i]);
        i++;
    }
}

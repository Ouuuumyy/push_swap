/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:01:42 by oukadir           #+#    #+#             */
/*   Updated: 2025/03/07 01:01:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_strlen(char *str)
{
    int i;
    i = 0;
    while (str[i])
        i++;
    return i;
}

int ft_atoi(char *str)
{
    int i;
    long res;
    int sign;

    i = 0;
    res = 0;
    sign = 1;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if ((str[i] == '-' || str[i] == '+'))
    {
        if(str[i] == '-')
            sign *= -1;
        i++;         
    }
    while (str[i] >= 48 && str[i] <= 57)
    {
        res = res * 10 + (str[i] - '0');
        if ((sign == 1 && res > INT_MAX) || (sign == -1 && res > (long)INT_MAX + 1))
        {
            write(2, "Error\n", 6);
            exit(1);
        }
        i++;
    }
    return (int)(sign * res);
}

int is_number(char *str)
{
    int i;
    i = 0;

    if (!str)
        return 0;
    if(str[i] == '-' || str[i] == '+')
        i++;
    if(!str[i])
        return 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}
char	*ft_strchr(const char *s, int c)
{
	char	ch;
	int		i;

	i = 0;
	ch = (char)c;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)(s + i));
		i++;
	}
	if (ch == '\0')
		return ((char *)(s + i));
	return (NULL);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:59:35 by elerika           #+#    #+#             */
/*   Updated: 2021/10/18 15:59:43 by elerika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

int ft_isspace(int  c)
{
    c = (unsigned char)c;
    if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
        return (1);
    return (0);
}

int ft_atoi(const char *str)
{
    int res;
    int sign;
    int i;
    
    i = 0;
    res = 0;
    sign = 1;
    if (!str)
        return (0);
    while (ft_isspace(str[i]))
        i++;
    if (str[i] == '-')
    {
        sign = - 1;
        i++;
    }
    if (str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
        res = (res * 10) + (str[i++] - '0');
    return (res * sign);
}
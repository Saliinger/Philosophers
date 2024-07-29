/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:46:19 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/29 13:03:48 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
    int		i;
    int		j;
    int		c;
    char	*cstr;

    i = 0;
    j = 0;
    c = 1;
    cstr = (char *)str;
    while (cstr[i] == 32 || (cstr[i] >= 9 && cstr[i] <= 13))
        ++i;
    if (cstr[i] == '-' || cstr[i] == '+')
    {
        if (cstr[i] == '-')
            c *= -1;
        i++;
    }
    while (cstr[i] >= '0' && cstr[i] <= '9')
    {
        j *= 10;
        j += cstr[i] - '0';
        ++i;
    }
    return (j * c);
}
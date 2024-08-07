/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:46:19 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/07 16:05:52 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	long long	i;
	long long	j;
	long long	signe;
	char		*cstr;

	i = 0;
	j = 0;
	signe = 1;
	cstr = (char *)str;
	while (cstr[i] == 32 || (cstr[i] >= 9 && cstr[i] <= 13))
		++i;
	if (cstr[i] == '-' || cstr[i] == '+')
	{
		if (cstr[i] == '-')
			signe *= -1;
		i++;
	}
	while (cstr[i] >= '0' && cstr[i] <= '9')
	{
		j *= 10;
		j += cstr[i] - '0';
		++i;
	}
	return (j * signe);
}

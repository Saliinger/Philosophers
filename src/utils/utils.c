/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:13:14 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/31 11:58:01 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_philo **philo)
{
	while (*philo)
	{
		printf("id: %d\n", (*philo)->id);
		*philo = (*philo)->next;
	}
}

bool	is_digit(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (ac >= i)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] >= '0' && av[i][j] <= '9')
				j++;
			else
				return (false);
		}
		i++;
	}
	return (true);
}

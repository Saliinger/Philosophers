/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:13:14 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/31 15:14:09 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	ft_print(t_philo **philo)
// {
//     t_philo	*node = *philo;

//  	while (node)
//  	{
//  		printf("id: %d\nnbr m: %d\n", node->id, node->number_of_meal);
//  		node = node->next;
//  	}
// }

long long	current_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_status(t_philo *philo, char *str, bool is_dead)
{
	if (philo->data->flag == 0)
	{
		pthread_mutex_lock(&philo->data->write);
		if (philo->data->flag == 0)
			printf("%lld %d %s\n", current_timestamp() - philo->start,
				philo->id, str);
		pthread_mutex_unlock(&philo->data->write);
	}
	if (is_dead == true)
	{
		pthread_mutex_lock(&philo->data->write);
		printf("%lld %d %s\n", current_timestamp() - philo->start, philo->id,
			str);
		pthread_mutex_unlock(&philo->data->write);
	}
}

bool	is_digit(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (ac > i)
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] >= '0' && av[i][j] <= '9') || (av[i][j] == '-'
					|| av[i][j] == '+'))
				j++;
			else
				return (false);
		}
		i++;
	}
	return (true);
}

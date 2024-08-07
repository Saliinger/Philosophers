/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:45:58 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/07 16:06:37 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_fork(t_data *data, t_philo **philo)
{
	int	i;

	i = 0;
	data->fork = malloc(data->number_of_philo * sizeof(pthread_mutex_t) + 1);
	if (!data->fork)
	{
		return ;
	}
	while (i < data->number_of_philo)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) != 0)
		{
			free(data->fork);
			ft_free(data, philo, true);
		}
		i++;
	}
	if (pthread_mutex_init(&data->lock, NULL) != 0)
	{
		free(data->fork);
		ft_free(data, philo, true);
	}
}

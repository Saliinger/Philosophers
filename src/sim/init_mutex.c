/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:45:58 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/10 16:27:24 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	error_mutex(t_data *data, t_philo **philo)
{
	if (data->fork)
		free(data->fork);
	printf("Error\nthe mutex init didn't go through\n");
	ft_free(data, philo, true);
}

void	init_mutex(t_data *data, t_philo **philo)
{
	int	i;

	i = 0;
	data->fork = malloc(data->number_of_philo * sizeof(pthread_mutex_t));
	if (!data->fork)
		ft_free(data, philo, true);
	while (i < data->number_of_philo)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) != 0)
			error_mutex(data, philo);
		i++;
	}
	if (pthread_mutex_init(&data->lock, NULL) != 0)
		error_mutex(data, philo);
	if (pthread_mutex_init(&data->write, NULL) != 0)
		error_mutex(data, philo);
}

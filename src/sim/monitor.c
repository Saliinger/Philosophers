/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:27:58 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/11 15:58:41 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	exit_m(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->lock);
	data->number_of_death += 1;
	ft_status(philo, "died");
	pthread_mutex_unlock(&data->lock);
	if (data->number_of_philo == 1)
		pthread_mutex_unlock(philo->l_fork);
}

void	*monitor(void *arg)
{
	t_philo		*philo;
	t_data		*data;
	long long	current_time;

	philo = (t_philo *)arg;
	data = philo->data;
	while (data->number_of_death == 0)
	{
		philo = (t_philo *)arg;
		while (philo)
		{
			current_time = current_timestamp();
			if (current_time > data->time_to_die + philo->last_meal)
			{
				exit_m(data, philo);
				return (NULL);
			}
			philo = philo->next;
		}
		usleep(1000);
	}
	return (NULL);
}

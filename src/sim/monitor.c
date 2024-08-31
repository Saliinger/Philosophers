/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:27:58 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/31 15:15:35 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo	*there_is_a_cadaver(t_philo **l_philo)
{
	t_philo	*philo;

	philo = *l_philo;
	while (philo)
	{
		if (philo->is_dead == true)
			return (philo);
		philo = philo->next;
	}
	return (NULL);
}

static void	exit_m(t_data *data, t_philo *philo)
{
	t_philo	*philo_dead;

	pthread_mutex_lock(&data->lock);
	data->flag = 1;
	pthread_mutex_unlock(&data->lock);
	pthread_mutex_unlock(philo->l_fork);
	if (data->philo_is_dead > 0)
	{
		philo_dead = there_is_a_cadaver(data->l_philo);
		if (philo_dead != NULL)
			ft_status(philo_dead, "is dead", true);
	}
}

static void	extend_dead_checker(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->lock);
	philo->is_dead = true;
	data->philo_is_dead += 1;
	pthread_mutex_unlock(&data->lock);
	exit_m(data, philo);
}

static bool	dead_checker(t_philo *philo, long long current_time, t_data *data)
{
	if (current_time > data->time_to_die + philo->last_meal)
	{
		extend_dead_checker(philo, data);
		return (true);
	}
	if (data->philo_has_eat_enough == data->number_of_philo)
	{
		exit_m(data, philo);
		return (true);
	}
	if (data->number_of_dishes > 0)
	{
		if (philo->has_eat_enough == false
			&& philo->number_of_meal >= data->number_of_dishes)
		{
			pthread_mutex_lock(&data->lock);
			data->philo_has_eat_enough++;
			philo->has_eat_enough = true;
			pthread_mutex_unlock(&data->lock);
		}
	}
	return (false);
}

void	*monitor(void *arg)
{
	t_philo		*philo;
	t_data		*data;
	long long	current_time;

	philo = (t_philo *)arg;
	data = philo->data;
	while (data->flag == 0)
	{
		philo = (t_philo *)arg;
		while (philo)
		{
			current_time = current_timestamp();
			if (dead_checker(philo, current_time, data) == true)
				return (NULL);
			philo = philo->next;
		}
	}
	return (NULL);
}

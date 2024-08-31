/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:09:47 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/31 15:13:57 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	if (philo->data->flag > 0)
		return ;
	ft_status(philo, "has taken a fork", false);
	pthread_mutex_lock(philo->r_fork);
	if (philo->data->flag > 0)
	{
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	ft_status(philo, "has taken a fork", false);
	ft_status(philo, "is eating", false);
	philo->last_meal = current_timestamp();
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	if (philo->data->number_of_dishes > 0)
		philo->number_of_meal++;
}

void	thinking(t_philo *philo)
{
	ft_status(philo, "is thinking", false);
	philo->last_think = current_timestamp();
}

void	sleeping(t_philo *philo)
{
	ft_status(philo, "is sleeping", false);
	philo->last_sleep = current_timestamp();
	usleep(philo->data->time_to_sleep * 1000);
}

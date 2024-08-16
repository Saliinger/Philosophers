/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:09:47 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/11 15:58:32 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	if (philo->data->flag > 0)
		return ;
	ft_status(philo, "has taken a fork");
	pthread_mutex_lock(philo->r_fork);
	if (philo->data->flag > 0)
		return ;
	ft_status(philo, "has taken a fork");
	ft_status(philo, "is eating");
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	if (philo->data->number_of_dishes > 0)
		philo->number_of_meal++;
	philo->last_meal = current_timestamp();
}

void	thinking(t_philo *philo)
{
	ft_status(philo, "is thinking");
	philo->last_think = current_timestamp();
}

void	sleeping(t_philo *philo)
{
	ft_status(philo, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
	philo->last_sleep = current_timestamp();
}

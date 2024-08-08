/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:09:47 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/07 17:32:16 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->l_fork) != 0)
		return ;
	ft_status(philo, "has taken the left fork");
	if (philo->has_a_r_fork == false || pthread_mutex_lock(&philo->r_fork) != 0)
	{
		pthread_mutex_unlock(&philo->l_fork);
		return ;
	}
	ft_status(philo, "has taken the right fork");
	ft_status(philo, "is eating");
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(&philo->r_fork);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 22:02:31 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/01 16:55:10 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    loop_death(t_philo *philo)
{
    long long life_time;

    philo->start = current_timestamp();
    life_time = philo->data->time_to_die + current_timestamp();
    while (life_time >= current_timestamp())
    {
        pthread_mutex_lock(&philo->l_fork);
        ft_status(philo, "has taken the left fork");
        pthread_mutex_lock(&philo->r_fork);
        ft_status(philo, "has taken the right fork");
        ft_status(philo, "is eating");
        usleep(philo->data->time_to_eat * 100);
        philo->last_meal = current_timestamp();
        pthread_mutex_unlock(&philo->l_fork);
        pthread_mutex_unlock(&philo->r_fork);
        ft_status(philo, "is sleeping");
        usleep(philo->data->time_to_sleep * 100);
        philo->last_sleep = current_timestamp();
        ft_status(philo, "is thinking");
        philo->last_think = current_timestamp();
    }
}

void    loop_meal(t_philo *philo)
{
    int i = 0;
    long long life_time;

    philo->start = current_timestamp();
    life_time = philo->data->time_to_die + current_timestamp();
    while (life_time >= current_timestamp()&& i < philo->data->number_of_dishes)
    {
        pthread_mutex_lock(&philo->l_fork);
        ft_status(philo, "has taken the left fork");
        pthread_mutex_lock(&philo->r_fork);
        ft_status(philo, "has taken the right fork");
        ft_status(philo, "is eating");
        usleep(philo->data->time_to_eat * 100);
        philo->last_meal = current_timestamp();
        pthread_mutex_unlock(&philo->l_fork);
        pthread_mutex_unlock(&philo->r_fork);
        ft_status(philo, "is sleeping");
        usleep(philo->data->time_to_sleep * 100);
        philo->last_sleep = current_timestamp();
        ft_status(philo, "is thinking");
        philo->last_think = current_timestamp();
        i++;
        life_time++;
    }
}

void	*routine(void *arg)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)arg;
	data = philo->data;

    if (data->number_of_dishes > 0) { loop_meal(philo); }
    else { loop_death(philo); }
	return (NULL);
}

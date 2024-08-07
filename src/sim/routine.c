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
    while (philo->data->number_of_death == 0)
    {
        printf("lt %lld\nlm %lld\nls %lld\ntd %lld\nps %lld\n", current_timestamp() - philo->last_think, current_timestamp() - philo->last_meal, current_timestamp() - philo->last_sleep, philo->data->time_to_die, philo->start);
        if (current_timestamp() > philo->data->time_to_die + philo->last_think || current_timestamp() > philo->data->time_to_die  + philo->last_meal|| philo->last_sleep > philo->data->time_to_die  + philo->last_sleep) {
            pthread_mutex_lock(&philo->data->lock);
            philo->data->number_of_death += 1;
            pthread_mutex_unlock(&philo->data->lock);
            return;
        }
        pthread_mutex_lock(&philo->l_fork);
        ft_status(philo, "has taken the left fork");
        pthread_mutex_lock(&philo->r_fork);
        ft_status(philo, "has taken the right fork");
        ft_status(philo, "is eating");
        usleep(philo->data->time_to_eat * 1000);
        pthread_mutex_unlock(&philo->l_fork);
        pthread_mutex_unlock(&philo->r_fork);
        philo->last_meal = current_timestamp();
        ft_status(philo, "is sleeping");
        usleep(philo->data->time_to_sleep * 1000);
        philo->last_sleep = current_timestamp();
        ft_status(philo, "is thinking");
        philo->last_think = current_timestamp();
    }
}

void    loop_meal(t_philo *philo)
{
    int i = 0;
    while (philo->data->number_of_death == 0 && i++ < philo->data->number_of_dishes)
    {
        printf("lt %lld\nlm %lld\nls %lld\ntd %lld\nps %lld\n", philo->data->time_to_die + philo->last_think, philo->data->time_to_die + philo->last_meal, philo->data->time_to_die + philo->last_sleep, current_timestamp(), philo->start);
        if (current_timestamp() > philo->data->time_to_die + philo->last_think || current_timestamp() > philo->data->time_to_die  + philo->last_meal|| philo->last_sleep > philo->data->time_to_die  + philo->last_sleep) {
            pthread_mutex_lock(&philo->data->lock);
            philo->data->number_of_death += 1;
            pthread_mutex_unlock(&philo->data->lock);
            return;
        }
        pthread_mutex_lock(&philo->l_fork);
        ft_status(philo, "has taken the left fork");
        pthread_mutex_lock(&philo->r_fork);
        ft_status(philo, "has taken the right fork");
        ft_status(philo, "is eating");
        usleep(philo->data->time_to_eat * 1000);
        pthread_mutex_unlock(&philo->l_fork);
        pthread_mutex_unlock(&philo->r_fork);
        philo->last_meal = current_timestamp();
        ft_status(philo, "is sleeping");
        usleep(philo->data->time_to_sleep * 1000);
        philo->last_sleep = current_timestamp();
        ft_status(philo, "is thinking");
        philo->last_think = current_timestamp();
    }
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
    if (philo->data->number_of_dishes > 0)
        loop_meal(philo);
    else
        loop_death(philo);
	return (NULL);
}

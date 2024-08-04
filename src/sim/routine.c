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

void	*routine(void *arg)
{
	//t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)arg;
	//data = philo->data;

	while (1)
	{
		pthread_mutex_lock(&philo->l_fork);
		ft_status(philo->id, "has taken the left fork");
		pthread_mutex_lock(&philo->r_fork);
		ft_status(philo->id, "has taken the right fork");
		ft_status(philo->id, "is eating");
		pthread_mutex_unlock(&philo->l_fork);
		pthread_mutex_unlock(&philo->r_fork);
		ft_status(philo->id, "is sleeping");
		ft_status(philo->id, "is thinking");
	}
	return (NULL);
}

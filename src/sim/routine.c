/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 22:02:31 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/07 17:15:33 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	loop_death(t_philo *philo)
{
	while (philo->data->number_of_death == 0)
	{
		eat(philo);
		sleeping(philo);
		thinking(philo);
	}
    return;
}

void	loop_meal(t_philo *philo)
{
	int	i;

	i = 0;
	while (philo->data->number_of_death == 0
		&& i++ < philo->data->number_of_dishes)
	{
		eat(philo);
		sleeping(philo);
		thinking(philo);
	}
    return;
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

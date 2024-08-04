/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:52:41 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/01 16:47:12 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread(t_data *data, t_philo **philo_l)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = *philo_l;
	while (i < data->number_of_philo)
	{
		pthread_create(&philo->thread, NULL, routine, philo);
		i++;
		philo = philo->next;
	}
	i = 0;
	philo = *philo_l;
	while (i < data->number_of_philo)
	{
		pthread_join(philo->thread, NULL);
		i++;
		philo = philo->next;
	}
}

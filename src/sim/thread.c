/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:52:41 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/01 15:59:29 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = data->philosophers;
	while (i < data->number_of_philo)
	{
		pthread_create(&philo->thread, NULL, routine, philo);
		i++;
		philo = philo->next;
	}
	i = 0;
	philo = data->philosophers;
	while (i < data->number_of_philo)
	{
		pthread_join(&philo->thread, NULL);
		i++;
		philo = philo->next;
	}
}

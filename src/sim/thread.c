/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:52:41 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/05 12:14:17 by anoukan          ###   ########.fr       */
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
		if (pthread_create(&philo->thread, NULL, routine, philo) != 0)
        {
            printf("Error\nthe creation of the thread has fail\n");
            ft_free(data, philo_l, true);
        }
		i++;
		philo = philo->next;
	}
	i = 0;
	philo = *philo_l;
	while (i < data->number_of_philo)
	{
		if (pthread_join(philo->thread, NULL) != 0)
        {
            printf("Error\nthe joining of the thread has fail\n");
            ft_free(data, philo_l, true);
        }
		i++;
		philo = philo->next;
	}
}

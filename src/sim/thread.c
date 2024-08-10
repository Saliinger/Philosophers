/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:52:41 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/08 12:11:30 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_time(t_philo **philo_l, t_data *data)
{
	int		i;
	t_philo	*philo;
    long long time;

	i = 0;
	philo = *philo_l;
    time = current_timestamp();
	while (i < data->number_of_philo)
	{
		philo->start = time;
		philo->last_think = time;
		philo->last_meal = time;
		philo->last_sleep = time;
		i++;
		philo = philo->next;
	}
}

static void	init_thread(t_philo **philo_l, t_data *data)
{
	t_philo	*philo;

	philo = *philo_l;
	while (philo)
	{
		if (pthread_create(&philo->thread, NULL, routine, philo) != 0)
		{
			printf("Error\nthe creation of the thread has fail\n");
			ft_free(data, philo_l, true);
		}
		philo = philo->next;
	}
    if (pthread_create(&data->monitor, NULL, monitor, *philo_l) != 0)
    {
        printf("Error\nthe creation of the thread has fail\n");
        ft_free(data, philo_l, true);
    }
}

static void	init_join(t_philo **philo_l, t_data *data)
{
	t_philo	*philo;

	philo = *philo_l;
	while (philo)
	{
		if (pthread_join(philo->thread, NULL) != 0)
		{
			printf("Error\nthe joining of the thread has fail\n");
			ft_free(data, philo_l, true);
		}
		philo = philo->next;
	}
    if (pthread_join(data->monitor, NULL) != 0)
    {
        printf("Error\nthe joining of the thread has fail\n");
        ft_free(data, philo_l, true);
    }
}

void	thread(t_data *data, t_philo **philo_l)
{
	init_time(philo_l, data);
	init_thread(philo_l, data);
	init_join(philo_l, data);
}

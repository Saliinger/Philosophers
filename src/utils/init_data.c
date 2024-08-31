/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:13:09 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/11 15:59:00 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *data, char **av, t_philo **philo)
{
	data->philo_has_eat_enough = 0;
	data->flag = 0;
	data->number_of_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->philo_is_dead = 0;
	if (av[5])
	{
		data->number_of_dishes = ft_atoi(av[5]);
		if (data->number_of_dishes <= 0)
		{
			printf("Error\nthe settings are <= 0\n");
			ft_free(data, philo, true);
		}
	}
	else
		data->number_of_dishes = -1;
	if (data->number_of_philo <= 0 || data->time_to_die <= 0
		|| data->time_to_eat <= 0 || data->time_to_sleep <= 0)
	{
		printf("Error\nthe settings are <= 0\n");
		ft_free(data, philo, true);
	}
}

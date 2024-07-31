/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:13:09 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/31 13:50:08 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	create_philo(t_philo **philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		new_philo(philo, i);
		i++;
	}
}

void	init_data(t_philo **philo, t_data *data, char **av)
{
	data->number_of_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->number_of_dishes = ft_atoi(av[5]);
	else
		data->number_of_dishes = -1;
	create_philo(philo, data);
}

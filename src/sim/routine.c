/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 22:02:31 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/10 16:27:32 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	first_turn(t_data *data)
{
	static int	nbr_p = 0;

	if (nbr_p == data->number_of_philo)
		return (true);
	else
		nbr_p++;
	return (false);
}

void	loop_death(t_philo *philo)
{
	while (philo->data->number_of_death == 0)
	{
		if (first_turn(philo->data) == false)
		{
			if (philo->id % 2 == 0)
				eat(philo);
		}
		else
			eat(philo);
		if (philo->data->number_of_death > 0)
			break ;
		sleeping(philo);
		if (philo->data->number_of_death > 0)
			break ;
		thinking(philo);
		if (philo->data->number_of_death > 0)
			break ;
	}
	return ;
}

void	loop_meal(t_philo *philo)
{
	int	i;

	i = 0;
	while (philo->data->number_of_death == 0
		&& i++ < philo->data->number_of_dishes)
	{
		if (first_turn(philo->data) == false)
		{
			if (philo->id % 2 == 0)
				eat(philo);
		}
		else
			eat(philo);
		if (philo->data->number_of_death > 0)
			break ;
		sleeping(philo);
		if (philo->data->number_of_death > 0)
			break ;
		thinking(philo);
		if (philo->data->number_of_death > 0)
			break ;
	}
	return ;
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

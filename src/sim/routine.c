/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 22:02:31 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/11 15:58:43 by anoukan          ###   ########.fr       */
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

/*static bool	number_of_meal(t_data *data)
{
	t_philo	*philo;

	if (!data->l_philo)
	{
		printf("Error: Linked list head is NULL\n");
		return (false);
	}
	philo = *data->l_philo;
	while (philo)
	{
		if (philo->number_of_meal < data->number_of_dishes)
			return (false);
		philo = philo->next;
	}
	return (true);
}*/

void	loop_death(t_philo *philo)
{
	while (philo->data->flag == 0)
	{
		if (first_turn(philo->data) == false)
		{
			if (philo->id % 2 == 0)
				eat(philo);
		}
		else
			eat(philo);
		if (philo->data->flag > 0)
			break ;
		sleeping(philo);
		if (philo->data->flag > 0)
			break ;
		thinking(philo);
		if (philo->data->flag > 0)
			break ;
	}
	return ;
}

void	loop_meal(t_philo *philo)
{
	while (philo->data->flag == 0)
	{
		if (first_turn(philo->data) == false)
		{
			if (philo->id % 2 == 0)
				eat(philo);
		}
		else
			eat(philo);
		if (philo->data->flag > 0)
			break ;
		sleeping(philo);
		if (philo->data->flag > 0)
			break ;
		thinking(philo);
		if (philo->data->flag > 0)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 22:02:52 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/27 11:16:45 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo	*there_is_a_cadaver(t_philo **l_philo)
{
	t_philo	*philo;

	philo = *l_philo;
	while (philo)
	{
		if (philo->is_dead == true)
			return (philo);
		philo = philo->next;
	}
	return (NULL);
}

void	end(t_data *data, t_philo **philo)
{
	t_philo	*philo_dead;

	philo_dead = there_is_a_cadaver(philo);
	if (philo_dead != NULL)
		ft_status(philo_dead, "is dead", true);
	printf("end of simulation\n");
	ft_free(data, philo, false);
}

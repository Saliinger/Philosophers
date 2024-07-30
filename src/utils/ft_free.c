/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:12:56 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/30 19:12:57 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_philo(t_philo **philo)
{
	t_philo	*temp;

	temp = *philo;
	while (*philo)
	{
		temp = temp->next;
		free(*philo);
		*philo = temp;
	}
	free(philo);
}

void	ft_free(t_data *data, t_philo **philo)
{
	if (philo)
		free_philo(philo);
	if (data)
		free(data);
}

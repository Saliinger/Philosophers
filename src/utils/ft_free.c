/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:12:56 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/07 16:29:53 by anoukan          ###   ########.fr       */
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

void	ft_free(t_data *data, t_philo **philo, bool fail)
{
	if (philo)
		free_philo(philo);
	if (data)
		free(data);
	if (fail == true)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:13:03 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/07 16:06:33 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	new_philo(t_data *data, t_philo **philo, int index)
{
	t_philo	*new;
	t_philo	*current;

	new = (t_philo *)malloc(sizeof(t_philo));
	if (!new)
		return ;
	new->next = NULL;
	new->id = index + 1;
	if (*philo == NULL)
		*philo = new;
	else
	{
		current = *philo;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	new->l_fork = data->fork[index];
	if (index != data->number_of_philo - 1)
		new->r_fork = data->fork[index + 1];
	else
		new->r_fork = data->fork[0];
	new->data = data;
}

void	create_philo(t_philo **philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		new_philo(data, philo, i);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:05:16 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/09 11:05:54 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	fork_philo(t_data *data, t_philo *new, int index)
{
	if (data->number_of_philo == 1)
	{
		new->l_fork = &data->fork[0];
		new->has_a_r_fork = false;
        new->r_fork = &data->fork[0];
	}
	else
	{
		new->l_fork = &data->fork[index];
		if (index != data->number_of_philo - 1)
			new->r_fork = &data->fork[index + 1];
		else
			new->r_fork = &data->fork[0];
		new->has_a_r_fork = true;
	}
}

static void	new_philo(t_data *data, t_philo **philo, int index)
{
	t_philo	*new;
	t_philo	*current;

	new = (t_philo *)malloc(sizeof(t_philo));
	if (!new)
		ft_free(data, philo, true);
	new->next = NULL;
	new->id = index + 1;
	fork_philo(data, new, index);
	if (*philo == NULL)
		*philo = new;
	else
	{
		current = *philo;
		while (current->next)
			current = current->next;
		current->next = new;
	}
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

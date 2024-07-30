/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:13:03 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/30 19:13:04 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	new_philo(t_philo **philo, int index)
{
	t_philo	*new;
	t_philo	*current;

	new = (t_philo *)malloc(sizeof(t_philo));
	if (!new)
		return ;
	new->next = NULL;
	new->id = index;
	if (*philo == NULL)
		*philo = new;
	else
	{
		current = *philo;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

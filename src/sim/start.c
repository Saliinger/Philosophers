/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:53:33 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/11 15:58:45 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	start(t_data *data, t_philo **philo)
{
	init_mutex(data, philo);
	create_philo(philo, data);
	thread(data, philo);
	// ft_print(philo);
	end(data, philo);
}

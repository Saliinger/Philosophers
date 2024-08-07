/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:53:33 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/07 16:06:01 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start(t_data *data, t_philo **philo)
{
	init_fork(data, philo);
	init_write(data, philo);
	create_philo(philo, data);
	thread(data, philo);
	end(data, philo);
}

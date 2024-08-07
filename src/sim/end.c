/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 22:02:52 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/07 16:06:42 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end(t_data *data, t_philo **philo)
{
	if (data->number_of_death >= 0)
	{
		printf("%d has died\n", (*philo)->data->number_of_death);
	}
	else
		printf("end of simulation\n");
	ft_free(data, philo, false);
}

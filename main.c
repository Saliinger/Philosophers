/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:12:39 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/01 15:52:10 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 5 || argc > 6)
		return (printf("you need to use Philo properly\n"), 0);
	if (is_digit(argc, argv) == false)
		return (printf("the settings are not digits\n"), 0);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (printf("Error\nmalloc data\n"), 0);
	data->philosophers = (t_philo **)malloc(sizeof(t_philo *));
	if (!data->philosophers)
		return (ft_free(data, data->philosophers),
			printf("Error\nmalloc philo\n"), 0);
	init_data(data, argv);
	start(data);
	return (0);
}

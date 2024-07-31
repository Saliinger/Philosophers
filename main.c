/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:12:39 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/31 22:10:25 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	**philo;

	if (argc < 5 || argc > 6)
		return (printf("you need to use Philo properly\n"), 0);
	if (is_digit(argc, argv) == false)
		return (printf("the settings are not digits\n"), 0);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (printf("Error\nmalloc data\n"), 0);
	philo = (t_philo **)malloc(sizeof(t_philo *));
	if (!philo)
		return (ft_free(data, philo), printf("Error\nmalloc philo\n"), 0);
	init_data(data, argv);
	return (0);
}

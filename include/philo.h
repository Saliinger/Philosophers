/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:13:21 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/31 13:50:29 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

// Struct
typedef struct s_data
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_dishes;
	pthread_mutex_t	*fork;
}					t_data;

typedef struct s_philo
{
	int				id;
	int				last_meal;
	int				last_sleep;
	int				last_think;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	r_fork;
	pthread_t		thread;
	struct s_philo	*next;
}					t_philo;

// Main

// Utils
int					ft_atoi(const char *str);
void				init_data(t_philo **philo, t_data *data, char **av);
void				ft_free(t_data *data, t_philo **philo);
void				new_philo(t_philo **philo, int index);
void				ft_print(t_philo **philo);
bool				is_digit(int ac, char **av);

#endif
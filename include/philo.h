/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:13:21 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/01 16:49:29 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

// Struct
typedef struct s_data
{
	int				number_of_philo;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				number_of_dishes;
	pthread_mutex_t	*fork;
}					t_data;

typedef struct s_philo
{
	int				id;
	long long		last_meal;
	long long		last_sleep;
	long long		last_think;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	r_fork;
	pthread_t		thread;
	struct s_philo	*next;
    struct s_data   *data;
}					t_philo;

// Sim
void				start(t_data *data, t_philo **philo);
void				create_philo(t_philo **philo, t_data *data);
void				init_fork(t_data *data);
void				*routine(void *arg);
void                thread(t_data *data, t_philo **philo_l);

// Utils
int					ft_atoi(const char *str);
void				init_data(t_data *data, char **av);
void				ft_free(t_data *data, t_philo **philo);
void				ft_status(int id, char *str);
long long			current_timestamp(void);
void				ft_print(t_philo **philo);
bool				is_digit(int ac, char **av);

#endif

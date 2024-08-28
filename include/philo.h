/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:13:21 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/28 14:15:37 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

// Struct
struct	s_philo;

typedef struct s_data
{
	int				number_of_philo;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				number_of_dishes;
	int				philo_has_eat_enough;
	int				flag;
	pthread_t		monitor;
	pthread_mutex_t	*fork;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
	struct s_philo	**l_philo;
}					t_data;

typedef struct s_philo
{
	int				id;
	long long		last_meal;
	long long		last_sleep;
	long long		last_think;
	int				number_of_meal;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_t		thread;
	struct s_philo	*next;
	struct s_data	*data;
	long long		start;
	bool			is_dead;
	bool			has_eat_enough;
}					t_philo;

// Sim
void				start(t_data *data, t_philo **philo);
void				create_philo(t_philo **philo, t_data *data);
void				init_mutex(t_data *data, t_philo **philo);
void				*routine(void *arg);
void				thread(t_data *data, t_philo **philo_l);
void				end(t_data *data, t_philo **philo);
void				*monitor(void *arg);

// Actions
void				sleeping(t_philo *philo);
void				thinking(t_philo *philo);
void				eat(t_philo *philo);

// Utils
int					ft_atoi(const char *str);
void				init_data(t_data *data, char **av, t_philo **philo);
void				ft_free(t_data *data, t_philo **philo, bool fail);
void				ft_status(t_philo *philo, char *str, bool is_dead);
long long			current_timestamp(void);
//void				ft_print(t_philo **philo);
bool				is_digit(int ac, char **av);

#endif

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

// Struct
typedef struct s_data {
    int number_of_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_dishes;
} t_data;

typedef struct s_philo {
    int id;
    int last_meal;
    int last_sleep;
    int last_think;
    struct s_philo *next;
} t_philo;

// Main

// Utils
int	ft_atoi(const char *str);
void init_data(t_data *data ,char **av);

#endif
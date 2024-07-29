#include "../../include/philo.h"

void init_data(t_data *data ,char **av)
{
    data->number_of_philo = ft_atoi(av[1]);
    data->time_to_die = ft_atoi(av[2]);
    data->time_to_eat = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);
    if (av[5])
        data->number_of_dishes = ft_atoi(av[5]);
    else
        data->number_of_dishes = -1;
}
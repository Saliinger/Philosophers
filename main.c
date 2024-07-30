#include "philo.h"

int main(int argc, char **argv)
{
    t_data *data;
    t_philo **philo;
    //pthread_t mutex;

    if (argc < 4)
        return (printf("you need to use the program as folow number_of_philosophers time_to_die time_to_eat time_to_sleep\n"
                       "[number_of_times_eargch_philosopher_must_eat]"), 0);
    data = (t_data *)malloc(sizeof(t_data));
    if(!data)
        return (printf("Error\nmalloc data\n"), 0);
    philo = (t_philo **)malloc(sizeof(t_philo *));
    if(!philo)
        return (ft_free(data, philo), 0);
    init_data(philo, data, argv);
    //printf("\nnbrp %d\ntmpd %d\ntmpe %d\ntmps %d\nnbrd %d\n", data->number_of_philo, data->time_to_die, data->time_to_eat, data->time_to_sleep, data->number_of_dishes);
    ft_free(data, philo);
    return (0);
}

#include "philo.h"

void    init_write(t_data *data, t_philo **philo)
{
    data->write = malloc(sizeof(pthread_mutex_t));
    if (!data->write)
    {
        printf("Error\nthe malloc of data->write has fail\n");
        free(data->write);
        ft_free(data, philo, true);
    }
    if (pthread_mutex_init(data->write, NULL) != 0)
    {
        printf("Error\nthe mutex init didn't go through\n");
        free(data->write);
        ft_free(data, philo, true);
    }
}
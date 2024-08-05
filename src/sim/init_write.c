#include "philo.h"

void    init_write(t_data *data, t_philo **philo)
{
    data->write = malloc(sizeof(pthread_mutex_t));
    if (!data->write)
    {
        free(data->write);
        ft_free(data, philo, true);
    }
    if (pthread_mutex_init(data->write, NULL) != 0)
    {
        free(data->write);
        ft_free(data, philo, true);
    }
}
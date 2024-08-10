#include "philo.h"

void *monitor(void *arg)
{
    t_philo *philo;
    t_data *data;
    long long current_time;

    philo = (t_philo *)arg;
    data = philo->data;
    while (data->number_of_death == 0)
    {
        philo = (t_philo *)arg;
        while (philo)
        {
            current_time = current_timestamp();
            if (current_time > data->time_to_die + philo->last_meal)
            {
                pthread_mutex_lock(&data->lock);
                data->number_of_death += 1;
                ft_status(philo, "died");
                pthread_mutex_unlock(&data->lock);
                return NULL;
            }
            philo = philo->next;
        }
        usleep(1000);
    }
    return NULL;
}

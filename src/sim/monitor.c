#include "philo.h"

void *monitor(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while (philo)
    {
        philo = (t_philo *)arg;
        while (philo)
        {
            if (current_timestamp() > philo->data->time_to_die + philo->last_think
			|| current_timestamp() > philo->data->time_to_die + philo->last_meal
			|| philo->last_sleep > philo->data->time_to_die + philo->last_sleep)
            {
                pthread_mutex_lock(&philo->data->lock);
                philo->data->number_of_death += 1;
                pthread_mutex_unlock(&philo->data->lock);
                return ;
            }
            philo = philo->next;
        }
    }
    return (NULL);
}

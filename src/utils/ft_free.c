#include "philo.h"

static void free_philo(t_philo **philo)
{
    t_philo *temp;

    temp = *philo;
    while (*philo)
    {
        temp = temp->next;
        free(*philo);
        *philo = temp;
    }
    free(philo);
}

void ft_free(t_data *data, t_philo **philo)
{
    if (philo)
        free_philo(philo);
     if(data)
        free(data);
}
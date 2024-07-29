#include "../../include/philo.h"

void new_philo(t_philo *philo)
{
    t_philo *new;

    new = (t_philo *)malloc(sizeof(t_philo));
    new->next = philo;
    philo = new;
}
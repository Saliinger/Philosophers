#include "philo.h"

void ft_print(t_philo **philo)
{
    while (*philo)
    {
        printf("id: %d\n", (*philo)->id);
        *philo = (*philo)->next;
    }
}
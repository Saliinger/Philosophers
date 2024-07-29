#include <../include/philo.h>

int main(int ac, char **av)
{
    t_data *data;
    t_philo *philo;
    pthread_t mutex;

    if (ac < 4)
        return (printf("you need to use the program as folow number_of_philosophers time_to_die time_to_eat time_to_sleep\n"
                       "[number_of_times_each_philosopher_must_eat]"), 0);
    data = (t_data *)malloc(sizeof(t_data));
    init_data(data, av);
    printf("nbrp %d\ntmpd %d\ntmpe %d\ntmps %d\nnbrd %d\n", data->number_of_philo, data->time_to_die, data->time_to_eat, data->time_to_sleep, data->number_of_dishes);
    philo = (t_philo *)malloc(sizeof(t_philo));

    return (0);
}

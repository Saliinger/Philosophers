#include <../include/philo.h>

int main(int ac, char **av)
{
    t_data *data;

    if (ac < 4)
        return (printf("you need to use the program as folow number_of_philosophers time_to_die time_to_eat time_to_sleep\n"
                       "[number_of_times_each_philosopher_must_eat]"), 0);
    data = (t_data *)malloc(sizeof(t_data));
    init_data(data, av);
    return (0);
}

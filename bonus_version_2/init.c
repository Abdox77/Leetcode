/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohdi <amohdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:34:22 by amohdi            #+#    #+#             */
/*   Updated: 2024/04/21 16:59:42 by amohdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void init_data(int ac, char **av, t_data *data)
{
    memset(data, 0, sizeof(t_data));
    init_time(ac, av, data);
    init_sems_names(data);
    init_sems(data);
    init_philos(data);
}

void init_time(int ac, char **av, t_data *data)
{
    if (ac == 6)
        data->must_eat_count = ft_atol(av[5]);
    data->time_to_die = ft_atol(av[2]);
    data->time_to_eat = ft_atol(av[3]);
    data->time_to_sleep = ft_atol(av[4]);
    data->num_of_philos = ft_atol(av[1]);
    if (data->num_of_philos > MAX_PHILOS || data->time_to_die < 60 || data->time_to_eat < 60
    || data->time_to_sleep < 60 || (ac == 6 && data->must_eat_count < 0))
        ft_error();
    data->start_time = get_time();
}

char *get_sem_name(char *name, int id)
{
    char *id_str;

    id_str = ft_itoa(id);
    if (!id_str)
        ft_error();
    return (ft_strjoin(name, id_str));
}

void init_sems_names(t_data *data)
{
    int i;

    i = -1;

    while(++i < data->num_of_philos)
    {
        data->forks_names[i] = get_sem_name("_fork_", i);
        if(NULL == data->forks_names[i])
            ft_error();
        data->time_sync_names[i] = get_sem_name("_time_", i);
        if (NULL == data->time_sync_names[i])
            ft_error();
        data->full_philo_names[i] = get_sem_name("_full_", i);
        if (NULL == data->full_philo_names[i])
            ft_error();
    }
}

void init_sems(t_data *data)
{
    int i;

    i = -1;
    while(++i < data->num_of_philos)
    {
        data->forks[i] = sem_open(data->forks_names[i], O_CREAT, 0644, 1);
        if (data->forks[i] == SEM_FAILED)
            ft_error();
        data->time_sems[i] = sem_open(data->time_sync_names[i], O_CREAT, 0644, 1);
        if (data->time_sems[i] == SEM_FAILED)
            ft_error();
    }
    data->print_sem = sem_open("_print_sync_sem_", O_CREAT, 0644, 1);
    if (SEM_FAILED == data->print_sem)
        ft_error();
    data->death_check = sem_open("_death_sync_", O_CREAT, 0644, 1);
    if (data->death_check == SEM_FAILED)
        ft_error();
}

void    init_philos(t_data *data)
{
    int i;

    i = 0;
    while (++i < data->num_of_philos)
    {
        data->philos[i].data = data;
        data->philos[i].id = i + 1;
        data->philos[i].eat_count = 0;
        data->philos[i].last_time_eaten = get_time();
        data->philos[i].right_fork = data->forks[i];
        data->philos[i].left_fork = data->forks[(i + 1) % data->num_of_philos];
        data->philos[i].time_sync = data->time_sems[i];
    }
}
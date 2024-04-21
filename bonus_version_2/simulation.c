/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohdi <amohdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:54:43 by amohdi            #+#    #+#             */
/*   Updated: 2024/04/21 17:03:41 by amohdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"




void create_philo(t_philo *philo)
{
    pid_t pid;

    pid = fork();
    if (pid == -1)
        ft_error();
    if (pid == 0)
    {
        pthread_create(&philo->monitor, NULL, monitor, philo);
        pthread_detach(philo->monitor);
        routine(philo);
    }
    else
        return;
}

void start_simulation(t_data *data)
{
    int i;

    i = -1;
    while(++i < data->num_of_philos)
        create_philo(&(data->philos[i]));
}
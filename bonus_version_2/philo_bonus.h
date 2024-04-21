/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohdi <amohdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:17:52 by amohdi            #+#    #+#             */
/*   Updated: 2024/04/21 16:44:39 by amohdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/wait.h>

#define MAX_PHILOS 200

typedef enum
{
    false,
    true
}   t_bool;

typedef struct s_data t_data;
typedef struct s_philo t_philo;

struct s_philo
{
    int         id;
    int         eat_count;
    long        last_time_eaten;
    sem_t       *time_sync;
    sem_t       *left_fork;
    sem_t       *right_fork;
    sem_t       *full_philo_notif;
    pthread_t   monitor;
    t_data      *data;
};

struct s_data
{
    t_philo    philos[MAX_PHILOS];
    sem_t      *forks[MAX_PHILOS];
    sem_t      *time_sems[MAX_PHILOS];
    sem_t      *print_sem;
    sem_t      *death_check;
    char       *forks_names[MAX_PHILOS];
    char       *time_sync_names[MAX_PHILOS];
    char       *full_philo_names[MAX_PHILOS];
    long       time_to_die;
    long       time_to_eat;
    long       time_to_sleep;
    long       start_time;
    int        num_of_philos;
    int        must_eat_count;
};



#endif
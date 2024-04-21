/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amohdi <amohdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:25:03 by amohdi            #+#    #+#             */
/*   Updated: 2024/04/21 16:41:09 by amohdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"




int main(int ac, char **av)
{
    t_data data;
    if (ac != 5 && ac != 6)
        ft_error();
    init_data(ac, av, &data);
    start_simulation(&data);
}
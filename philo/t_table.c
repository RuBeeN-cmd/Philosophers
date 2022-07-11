/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_table.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 07:06:02 by rrollin           #+#    #+#             */
/*   Updated: 2022/07/11 07:51:14 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo *init_philo(int nb_philo)
{
    t_philo *philo;

    philo = malloc(sizeof(t_philo) * nb_philo);
    if (!philo)
        return (NULL);
    while (nb_philo--)
    {
        philo[nb_philo].id = nb_philo;
        philo[nb_philo].eat_count = 0;
        philo[nb_philo].state = THINKING;
    }
    return (philo);
}

t_table *init_table(int argc, char *argv[])
{
    t_table *table;

    if (check_args(argc, argv))
        return (NULL);
    table = malloc(sizeof(t_table));
    if (!table)
        return (NULL);
    table->nb_philo = ft_atoi(argv[1]);
    table->time_to_die = ft_atoi(argv[2]);
    table->time_to_eat = ft_atoi(argv[3]);
    table->time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        table->nb_must_eat = ft_atoi(argv[5]);
    else
        table->nb_must_eat = table->nb_philo;
    table->philo = init_philo(table->nb_philo);
    if (!table->philo)
    {
        free(table);
        return (NULL);
    }
    return (table);
}

void    destroy_table(t_table *table)
{
    free(table->philo);
    free(table);
}
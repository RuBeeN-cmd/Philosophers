/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 06:36:32 by rrollin           #+#    #+#             */
/*   Updated: 2022/07/11 07:52:06 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdlib.h>
#include <stdio.h>

typedef enum e_philo_state
{
    THINKING,
    EATING,
    SLEEPING,
    DEAD
} t_philo_state;

typedef struct s_philo
{
    int id;
    int eat_count;
    t_philo_state state;
} t_philo;

typedef struct s_table
{
    int nb_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int nb_must_eat;
    t_philo *philo;
} t_table;

t_table *init_table(int argc, char *argv[]);
void    destroy_table(t_table *table);
int     ft_atoi(char *str);
int     check_args(int argc, char *argv[]);


#endif
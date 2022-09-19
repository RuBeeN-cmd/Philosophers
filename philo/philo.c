/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 09:28:08 by rrollin           #+#    #+#             */
/*   Updated: 2022/09/05 11:04:46 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

static t_philo	init_philo_values(unsigned int id, t_program *program)
{
	t_philo	philo;

	philo.id = id;
	philo.eat_nb = 0;
	philo.program = program;
	return (philo);
}

static void	init_philo_list_thread(t_philo *philo_list, unsigned int size,
void *(*routine)(void *))
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		pthread_create(&(philo_list[i].thread), NULL, routine,
			&(philo_list[i]));
		gettimeofday(&(philo_list[i].last_eat_timestamp), NULL);
		i++;
	}
}

t_philo	*init_philo_list(unsigned int size, t_program *program)
{
	t_philo			*philo_list;
	unsigned int	i;

	philo_list = malloc(sizeof(t_philo) * size);
	i = 0;
	while (i < size)
	{
		philo_list[i] = init_philo_values(i + 1, program);
		philo_list[i].left_fork = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philo_list[i].left_fork, NULL);
		if (i)
			philo_list[i].right_fork = philo_list[i - 1].left_fork;
		i++;
	}
	philo_list[0].right_fork = philo_list[size - 1].left_fork;
	init_philo_list_thread(philo_list, size, routine);
	return (philo_list);
}

void	destroy_philo_list(t_philo *philo_list, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		pthread_mutex_destroy(philo_list[i].left_fork);
		free(philo_list[i++].left_fork);
	}
	free(philo_list);
}

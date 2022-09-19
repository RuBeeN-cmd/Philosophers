/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:31:38 by rrollin           #+#    #+#             */
/*   Updated: 2022/09/12 11:40:16 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	philo_take_fork(t_philo *philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	print_action(philo, "has taken a fork");
}

void	philo_eat(t_philo *philo)
{
	print_action(philo, "is eating");
	pthread_mutex_lock(&(philo->program->eat_timestamp_mutex));
	gettimeofday(&(philo->last_eat_timestamp), NULL);
	pthread_mutex_unlock(&(philo->program->eat_timestamp_mutex));
	usleep(philo->program->time_eat * 1000);
	pthread_mutex_lock(&(philo->program->eat_nb_mutex));
	philo->eat_nb++;
	pthread_mutex_unlock(&(philo->program->eat_nb_mutex));
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	philo_sleep(t_philo *philo)
{
	print_action(philo, "is sleeping");
	usleep(philo->program->time_sleep * 1000);
}

void	philo_die(t_philo *philo)
{
	print_action(philo, "died");
	pthread_mutex_lock(&(philo->program->is_simu_running_mutex));
	philo->program->is_simu_running = 0;
	pthread_mutex_unlock(&(philo->program->is_simu_running_mutex));
}

void	philo_think(t_philo *philo)
{
	print_action(philo, "is thinking");
}

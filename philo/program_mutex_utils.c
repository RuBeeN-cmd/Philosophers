/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_mutex_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:04:18 by rrollin           #+#    #+#             */
/*   Updated: 2022/09/12 10:40:04 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	check_simu_running(t_program *program)
{
	pthread_mutex_lock(&(program->is_simu_running_mutex));
	if (program->is_simu_running)
	{
		pthread_mutex_unlock(&(program->is_simu_running_mutex));
		return (1);
	}
	pthread_mutex_unlock(&(program->is_simu_running_mutex));
	return (0);
}

unsigned int	get_eat_nb(t_philo *philo)
{
	unsigned int	eat_nb;

	pthread_mutex_lock(&(philo->program->eat_nb_mutex));
	eat_nb = philo->eat_nb;
	pthread_mutex_unlock(&(philo->program->eat_nb_mutex));
	return (eat_nb);
}

struct timeval	get_eat_timestamp(t_philo *philo)
{
	struct timeval	eat_timestamp;

	pthread_mutex_lock(&(philo->program->eat_timestamp_mutex));
	eat_timestamp = philo->last_eat_timestamp;
	pthread_mutex_unlock(&(philo->program->eat_timestamp_mutex));
	return (eat_timestamp);
}

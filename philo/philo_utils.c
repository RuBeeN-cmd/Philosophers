/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:06:08 by rrollin           #+#    #+#             */
/*   Updated: 2022/09/12 10:39:57 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	print_action(t_philo *philo, char *action)
{
	unsigned int	elapsed_time;

	if (!check_simu_running(philo->program))
		return ;
	elapsed_time = get_elapsed_time(philo->program->timestamp);
	pthread_mutex_lock(&(philo->program->print_mutex));
	printf("%d %d %s\n", elapsed_time, philo->id, action);
	pthread_mutex_unlock(&(philo->program->print_mutex));
}

int	philo_enough_ate(t_philo *philo)
{
	return (!(philo->program->nb_philo_eat == -1
			|| (int) get_eat_nb(philo) < philo->program->nb_philo_eat));
}

int	philo_time_over(t_philo *philo)
{
	return (get_elapsed_time(get_eat_timestamp(philo))
		>= (unsigned int) philo->program->time_die);
}

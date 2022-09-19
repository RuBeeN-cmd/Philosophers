/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:11:45 by rrollin           #+#    #+#             */
/*   Updated: 2022/09/15 09:24:13 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	execute_cycle(t_philo *philo)
{
	philo_take_fork(philo, philo->left_fork);
	if (!check_simu_running(philo->program))
	{
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	philo_take_fork(philo, philo->right_fork);
	if (!check_simu_running(philo->program))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	philo_eat(philo);
	if (!check_simu_running(philo->program))
		return ;
	philo_sleep(philo);
	if (!check_simu_running(philo->program))
		return ;
	philo_think(philo);
}

void	start_loop(t_philo *philo)
{
	if (!(philo->id % 2))
		usleep(500);
	while (check_simu_running(philo->program) && !philo_enough_ate(philo))
		execute_cycle(philo);
}

void	*routine(void *void_philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *) void_philo_ptr;
	if (philo->program->nb_philo == 1)
	{
		philo_take_fork(philo, philo->left_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	else
		start_loop(philo);
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_program	*program;

	if (argc != 5 && argc != 6)
		return (1);
	program = init_program(argc - 1, argv + 1);
	if (!program)
		return (1);
	check_philo_death(program);
	destroy_program(program);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:38:18 by rrollin           #+#    #+#             */
/*   Updated: 2022/09/12 09:41:49 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

t_program	*init_program_values(int arg_nb, char *args[])
{
	t_program		*program;

	if (are_wrong_args(arg_nb, args))
		return (NULL);
	program = malloc(sizeof(t_program));
	program->nb_philo = ft_atoi(args[0]);
	program->time_die = ft_atoi(args[1]);
	program->time_eat = ft_atoi(args[2]);
	program->time_sleep = ft_atoi(args[3]);
	if (arg_nb == 5)
		program->nb_philo_eat = ft_atoi(args[4]);
	else
		program->nb_philo_eat = -1;
	program->all_philo_ate = 0;
	program->is_simu_running = 1;
	gettimeofday(&(program->timestamp), NULL);
	return (program);
}

void	init_program_mutex(t_program *program)
{
	pthread_mutex_init(&program->print_mutex, NULL);
	pthread_mutex_init(&program->eat_nb_mutex, NULL);
	pthread_mutex_init(&program->eat_timestamp_mutex, NULL);
	pthread_mutex_init(&program->is_simu_running_mutex, NULL);
}

void	unlock_all_fork(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->nb_philo)
		pthread_mutex_unlock(program->philo[i++].left_fork);
}

void	join_all_thread(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->nb_philo)
		pthread_join(program->philo[i++].thread, NULL);
}

void	destroy_program_mutex(t_program *program)
{
	pthread_mutex_destroy(&(program->print_mutex));
	pthread_mutex_destroy(&(program->eat_nb_mutex));
	pthread_mutex_destroy(&(program->eat_timestamp_mutex));
	pthread_mutex_destroy(&(program->is_simu_running_mutex));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:21:47 by rrollin           #+#    #+#             */
/*   Updated: 2022/09/12 10:40:01 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	all_philo_ate(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->nb_philo && philo_enough_ate(&(program->philo[i])))
		i++;
	return (i == program->nb_philo);
}

void	check_philo_death(t_program *program)
{
	int	i;

	while (!(program->all_philo_ate) && check_simu_running(program))
	{
		i = 0;
		while (i < program->nb_philo && check_simu_running(program))
		{
			if (!philo_enough_ate(&(program->philo[i]))
				&& philo_time_over(&(program->philo[i])))
				philo_die(&(program->philo[i]));
			i++;
		}
		program->all_philo_ate = all_philo_ate(program);
	}
}

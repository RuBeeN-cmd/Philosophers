/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:16:25 by rrollin           #+#    #+#             */
/*   Updated: 2022/09/12 12:18:13 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

t_program	*init_program(int arg_nb, char *args[])
{
	t_program		*program;

	program = init_program_values(arg_nb, args);
	if (!program)
		return (NULL);
	init_program_mutex(program);
	program->philo = init_philo_list(program->nb_philo, program);
	return (program);
}

void	destroy_program(t_program *program)
{
	join_all_thread(program);
	destroy_program_mutex(program);
	destroy_philo_list(program->philo, program->nb_philo);
	free(program);
}

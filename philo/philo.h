/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:25:05 by rrollin           #+#    #+#             */
/*   Updated: 2022/09/12 10:35:55 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include<pthread.h>
# include<stdlib.h>
# include<stdio.h>
# include<unistd.h>
# include<sys/time.h>

typedef struct s_philo
{
	unsigned int		id;
	unsigned int		eat_nb;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_t			thread;
	struct s_program	*program;
	struct timeval		last_eat_timestamp;
}				t_philo;

typedef struct s_program
{
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_philo_eat;
	struct timeval	timestamp;
	t_philo			*philo;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	eat_nb_mutex;
	pthread_mutex_t	eat_timestamp_mutex;
	pthread_mutex_t	is_simu_running_mutex;
	unsigned int	all_philo_ate;
	unsigned int	is_simu_running;
}				t_program;

/*  main.c  */
void			*routine(void *void_philo_ptr);

/*  program.c  */
t_program		*init_program(int arg_nb, char *args[]);
void			destroy_program(t_program *program);

/*  program_utils.c  */
t_program		*init_program_values(int arg_nb, char *args[]);
void			init_program_mutex(t_program *program);
void			unlock_all_fork(t_program *program);
void			join_all_thread(t_program *program);
void			destroy_program_mutex(t_program *program);

/*  program_mutex_utils.c  */

int				check_simu_running(t_program *program);
unsigned int	get_eat_nb(t_philo *philo);
struct timeval	get_eat_timestamp(t_philo *philo);

/*  check_args.c  */
int				is_wrong_nb_format(char *arg);
int				are_wrong_nb_format(int arg_nb, char *args[]);
int				are_wrong_args(int arg_nb, char *args[]);

/*  utils.c  */
unsigned int	ft_strlen(char *str);
int				ft_atoi(char *arg);
unsigned int	get_elapsed_time(struct timeval start);
int				ft_strcmp(char *s1, char *s2);

/*  philo.c  */
t_philo			*init_philo_list(unsigned int size, t_program *program);
void			destroy_philo_list(t_philo *philo_list, unsigned int size);

/*  philo_actions.c  */
void			philo_take_fork(t_philo *philo, pthread_mutex_t *fork);
void			philo_eat(t_philo *philo);
void			philo_sleep(t_philo *philo);
void			philo_die(t_philo *philo);
void			philo_think(t_philo *philo);

/*  philo_utils.c  */
void			print_action(t_philo *philo, char *action);
int				philo_enough_ate(t_philo *philo);
int				philo_time_over(t_philo *philo);

/*  check_death  */
void			check_philo_death(t_program *program);
int				all_philo_ate(t_program *program);

#endif

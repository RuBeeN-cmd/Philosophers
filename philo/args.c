/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 07:37:59 by rrollin           #+#    #+#             */
/*   Updated: 2022/07/11 07:49:53 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int check_arg_value(char *arg)
{
    int len;
    if (ft_atoi(arg) < 0)
        return (EXIT_FAILURE);
    len = 0;
    while (*arg)
    {
        if (*arg < '0' || *arg > '9')
            return (EXIT_FAILURE);
        len++;
        arg++;
    }
    if (len > 10)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

static int check_args_value(int argc, char *argv[])
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (check_arg_value(argv[i]))
            return (EXIT_FAILURE);
        i++;
    }
    return (EXIT_SUCCESS);
}

int check_args(int argc, char *argv[])
{
    if (argc != 5 && argc != 6)
    {
        printf("Usage: ./philo nb_philo t_die t_eat t_sleep [nb_each_eat]\n");
        return (EXIT_FAILURE);
    }
    if (check_args_value(argc, argv))
    {
        printf("Error: Invalid(s) parameter(s)\n");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

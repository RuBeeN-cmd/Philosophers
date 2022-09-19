/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:27:21 by rrollin           #+#    #+#             */
/*   Updated: 2022/09/12 09:47:33 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	is_wrong_nb_format(char *arg)
{
	int	result;
	int	new_result;
	int	i;

	if (!arg)
		return (1);
	result = 0;
	i = 0;
	if (!ft_strcmp(arg, "-2147483648"))
		return (0);
	if (arg[0] == '-')
		i++;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		new_result = result * 10 + arg[i] - '0';
		if (new_result < result)
			return (1);
		result = new_result;
		i++;
	}
	return (0);
}

int	are_wrong_nb_format(int arg_nb, char *args[])
{
	int	i;

	i = 0;
	while (i < arg_nb)
	{
		if (is_wrong_nb_format(args[i]))
			return (1);
		i++;
	}
	return (0);
}

int	are_wrong_args(int arg_nb, char *args[])
{
	int	i;
	int	nb;

	if (are_wrong_nb_format(arg_nb, args))
		return (1);
	i = 0;
	while (i < arg_nb)
	{
		nb = ft_atoi(args[i]);
		if (nb < 0)
			return (1);
		if (!i)
			if (!nb || nb > 200)
				return (1);
		i++;
	}
	return (0);
}

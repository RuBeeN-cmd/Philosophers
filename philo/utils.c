/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:22:41 by rrollin           #+#    #+#             */
/*   Updated: 2022/09/12 10:06:25 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_atoi(char *arg)
{
	int	result;
	int	coef;
	int	i;

	coef = 1;
	i = 0;
	if (!ft_strcmp(arg, "-2147483648"))
		return (-2147483648);
	if (arg[0] == '-')
	{
		coef = -1;
		i++;
	}
	result = 0;
	while (arg[i])
	{
		result = result * 10 + arg[i] - '0';
		i++;
	}
	return (result * coef);
}

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		else
			i++;
	}
	return (0);
}

unsigned int	get_elapsed_time(struct timeval start)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	return ((end.tv_sec * 1000 + end.tv_usec / 1000)
		- (start.tv_sec * 1000 + start.tv_usec / 1000));
}

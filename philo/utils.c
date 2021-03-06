/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 07:38:12 by rrollin           #+#    #+#             */
/*   Updated: 2022/07/11 07:39:23 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_atoi(char *str)
{
    int nb;

    nb = 0;
    while (*str >= '0' && *str <= '9')
    {
        nb = nb * 10 + *str - '0';
        str++;
    }
    return (nb);
}

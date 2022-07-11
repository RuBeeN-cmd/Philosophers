/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 06:31:22 by rrollin           #+#    #+#             */
/*   Updated: 2022/07/11 07:56:30 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char *argv[])
{
    t_table *table;

    table = init_table(argc, argv);
    if (!table)
        return (EXIT_FAILURE);
    destroy_table(table);
    return (EXIT_SUCCESS);
}
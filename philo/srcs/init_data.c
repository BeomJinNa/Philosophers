/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:07:05 by bena              #+#    #+#             */
/*   Updated: 2023/06/22 22:35:28 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_data.h"

int	init_data(t_stat *stat, t_args *args)
{
	int	i;

	stat->total_num = args->number_of_philosophers;
	stat->philo = (t_philo *)malloc(sizeof(t_philo) * (stat->total_num + 1));
	if (stat->philo == NULL)
		return (-1);
	memset(stat->philo, 0, sizeof(t_philo) * (stat->total_num + 1));
	stat->fork = (t_fork *)malloc(sizeof(t_fork) * (stat->total_num + 1));
	if (stat->fork == NULL)
	{
		free(stat->philo);
		return (-1);
	}
	memset(stat->fork, 0, sizeof(t_fork) * (stat->total_num + 1));
	i = -1;
	while (++i < args->number_of_philosophers)
		set_data(i, stat, args);
	stat->philo[--i].right = stat->fork;
	return (0);
}

static void	set_data(int index, t_stat *stat, t_args *args)
{
	stat->fork[index].index = index + 1;
	stat->philo[index].index = index + 1;
	stat->philo[index].time_to_die = args->time_to_die;
	stat->philo[index].time_to_eat = args->time_to_eat;
	stat->philo[index].time_to_sleep = args->time_to_sleep;
	stat->philo[index].goal = args->number_of_times_each_philosopher_must_eat;
	stat->philo[index].left = stat->fork + index;
	stat->philo[index].right = stat->fork + index + 1;
}

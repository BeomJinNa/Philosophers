/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:07:05 by bena              #+#    #+#             */
/*   Updated: 2023/06/24 20:26:07 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_data.h"

void	set_arguments(t_args *args, int *array)
{
	args->number_of_philosophers = array[0];
	args->time_to_die = array[1];
	args->time_to_eat = array[2];
	args->time_to_sleep = array[3];
	args->number_of_times_each_philosopher_must_eat = array[4];
}

int	init_data(t_stat *stat, t_args *args)
{
	int	i;

	memset(stat, 0, sizeof(t_stat));
	stat->total_num = args->number_of_philosophers;
	if (alloc_philo(stat))
		return (-1);
	if (alloc_fork(stat))
		return (-1);
	i = -1;
	while (++i < args->number_of_philosophers)
		set_data(i, stat, args);
	stat->philo[--i].right = stat->fork;
	return (0);
}

static void	set_data(int index, t_stat *stat, t_args *args)
{
	stat->fork[index].index = index + 1;
	stat->philo[index].stat = stat;
	stat->philo[index].index = index + 1;
	stat->philo[index].time_to_die = args->time_to_die;
	stat->philo[index].time_to_eat = args->time_to_eat;
	stat->philo[index].time_to_sleep = args->time_to_sleep;
	stat->philo[index].goal = args->number_of_times_each_philosopher_must_eat;
	stat->philo[index].left = stat->fork + index;
	stat->philo[index].right = stat->fork + index + 1;
}

static int	alloc_philo(t_stat *stat)
{
	stat->philo = (t_philo *)malloc(sizeof(t_philo) * stat->total_num);
	if (stat->philo == NULL)
		return (-1);
	memset(stat->philo, 0, sizeof(t_philo) * stat->total_num);
	return (0);
}

static int	alloc_fork(t_stat *stat)
{
	stat->fork = (t_fork *)malloc(sizeof(t_fork) * stat->total_num);
	if (stat->fork == NULL)
	{
		free(stat->philo);
		return (-1);
	}
	memset(stat->fork, 0, sizeof(t_fork) * stat->total_num);
	return (0);
}

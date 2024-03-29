/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:22:02 by bena              #+#    #+#             */
/*   Updated: 2023/07/30 18:05:34 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_simulation.h"

int	run_simulation(t_stat *stat, int *philo_errno)
{
	*philo_errno = init_mutexes(stat);
	if (*philo_errno)
		return (*philo_errno);
	*philo_errno = init_threads(stat);
	if (*philo_errno)
		return (destroy_mutexes(stat->total_num, stat, *philo_errno));
	*philo_errno = run_loop(stat);
	pthread_mutex_lock(&stat->mutex_print);
	printf("\033[1mEnd simulation\033[0m\n");
	pthread_mutex_unlock(&stat->mutex_print);
	release_threads(stat->total_num, stat, 1);
	while (get_terminated_threads(stat) < stat->total_num)
		usleep(100);
	destroy_mutexes(stat->total_num, stat, 1);
	return (*philo_errno);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:22:02 by bena              #+#    #+#             */
/*   Updated: 2023/06/25 19:27:22 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_simulation.h"

int	run_simulation(t_stat *stat, int *philo_errno)
{
	int	time;

	time = get_elapsed_time(0);
	*philo_errno = init_mutexes(stat);
	if (*philo_errno)
		return (*philo_errno);
	*philo_errno = init_threads(stat);
	if (*philo_errno)
		return (destroy_mutexes(stat->total_num, stat, *philo_errno));
	*philo_errno = run_loop(stat);
	printf("\033[1mEnd simulation\033[0m\n");
	release_threads(stat->total_num, stat, 1);
	while (get_terminated_threads(stat) < stat->total_num)
		usleep(100);
	destroy_mutexes(stat->total_num, stat, 1);
	return (*philo_errno);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:25:31 by bena              #+#    #+#             */
/*   Updated: 2023/06/23 21:27:20 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_threads.h"

int	init_threads(t_stat *stat)
{
	int			i;
	const int	time = get_elapsed_time(0);

	i = 0;
	while (i < stat->total_num)
	{
		stat->philo[i].time_to_start = time + 101;
		if (i + 1 < stat->total_num)
		{
			stat->philo[i].time_to_start = time + 100;
			stat->philo[i + 1].time_to_start = time + 101;
		}
		if (pthread_create(&stat->philo[i].tid, NULL,
				run_thread, &stat->philo[i]))
			return (release_threads(i, stat));
		if (i + 1 < stat->total_num)
			if (pthread_create(&stat->philo[i + 1].tid, NULL,
					run_thread, &stat->philo[i + 1]))
				return (release_threads(i + 1, stat));
		i += 2;
	}
	return (0);
}

int	release_threads(int index, t_stat *stat)
{
	int	i;

	stat->terminate_threads = 1;
	i = -1;
	while (++i < index)
		pthread_detach(stat->philo[index].tid);
	return (M_ERROR_THREAD_ALLOC);
}

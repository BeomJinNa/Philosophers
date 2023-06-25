/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:25:31 by bena              #+#    #+#             */
/*   Updated: 2023/06/25 19:41:55 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stat.h"
#include "e_private_errors.h"

void	*run_thread(void *info);
int		get_elapsed_time(int init);
int		release_threads(int index, t_stat *stat, int rt_errno);

int	init_threads(t_stat *stat)
{
	int			i;
	const int	time = get_elapsed_time(0);

	i = 0;
	while (i < stat->total_num)
	{
		stat->philo[i].time_to_start = time + 100 + stat->delay;
		stat->philo[i].last_meal_time = time + 100;
		if (i + 1 < stat->total_num)
		{
			stat->philo[i].time_to_start = time + 100;
			stat->philo[i + 1].time_to_start = time + 100 + stat->delay;
			stat->philo[i + 1].last_meal_time = time + 100;
		}
		if (pthread_create(&stat->philo[i].tid, NULL,
				run_thread, &stat->philo[i]))
			return (release_threads(i, stat, M_ERROR_THREAD_ALLOC));
		if (i + 1 < stat->total_num)
			if (pthread_create(&stat->philo[i + 1].tid, NULL,
					run_thread, &stat->philo[i + 1]))
				return (release_threads(i + 1, stat, M_ERROR_THREAD_ALLOC));
		i += 2;
	}
	return (0);
}

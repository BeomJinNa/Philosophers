/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:22:02 by bena              #+#    #+#             */
/*   Updated: 2023/06/23 23:35:33 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_simulation.h"

int	run_simulation(t_stat *stat, int *philo_errno)
{
	int	time;

	time = get_elapsed_time(0);
	//create threads
	*philo_errno = init_threads(stat);
	if (*philo_errno)
		return (*philo_errno);
	//threads are created after here
	*philo_errno = run_loop(stat);
	//threads will be released here
	release_threads(stat->total_num, stat, *philo_errno);
	//마지막 인자는 큰 의미 없음 philo_errno대신 1 넣어도 무방
	if (*philo_errno)
		return (*philo_errno);
	return (0);
}

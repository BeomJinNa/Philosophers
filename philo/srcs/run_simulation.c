/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:22:02 by bena              #+#    #+#             */
/*   Updated: 2023/06/23 21:46:48 by bena             ###   ########.fr       */
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
	//run_loop
	release_threads(stat->total_num, stat);
	return (0);
}

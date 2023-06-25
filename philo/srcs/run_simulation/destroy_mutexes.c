/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 23:20:11 by bena              #+#    #+#             */
/*   Updated: 2023/06/25 20:06:14 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stat.h"

void		set_simulation_status(t_stat *stat, int value);
static void	destroy_const_mutexes(t_stat *stat);

int	destroy_mutexes(int index, t_stat *stat, int rt_errno)
{
	int	i;

	set_simulation_status(stat, rt_errno);
	i = -1;
	while (++i < index)
		pthread_mutex_destroy(&stat->fork[i].mutex);
	destroy_const_mutexes(stat);
	return (rt_errno);
}

static void	destroy_const_mutexes(t_stat *stat)
{
	pthread_mutex_destroy(&stat->mutex_termination);
	pthread_mutex_destroy(&stat->mutex_finished);
	pthread_mutex_destroy(&stat->mutex_print);
}

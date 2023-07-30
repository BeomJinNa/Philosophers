/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutexes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:25:31 by bena              #+#    #+#             */
/*   Updated: 2023/07/30 17:41:22 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stat.h"
#include "e_private_errors.h"

int			destroy_mutexes(int index, t_stat *stat, int rt_errno);
static int	init_const_mutexes(t_stat *stat);

int	init_mutexes(t_stat *stat)
{
	int	i;

	if (init_const_mutexes(stat))
		return (M_ERROR_MUTEX_INIT);
	i = -1;
	while (++i < stat->total_num)
		if (pthread_mutex_init(&stat->fork[i].mutex, NULL))
			return (destroy_mutexes(i, stat, M_ERROR_MUTEX_INIT));
	return (0);
}

static int	init_const_mutexes(t_stat *stat)
{
	if (pthread_mutex_init(&stat->mutex_status, NULL))
		;
	else if (pthread_mutex_init(&stat->mutex_termination, NULL))
		pthread_mutex_destroy(&stat->mutex_status);
	else if (pthread_mutex_init(&stat->mutex_finished, NULL))
	{
		pthread_mutex_destroy(&stat->mutex_status);
		pthread_mutex_destroy(&stat->mutex_termination);
	}
	else if (pthread_mutex_init(&stat->mutex_print, NULL))
	{
		pthread_mutex_destroy(&stat->mutex_status);
		pthread_mutex_destroy(&stat->mutex_termination);
		pthread_mutex_destroy(&stat->mutex_finished);
	}
	else
		return (0);
	return (1);
}

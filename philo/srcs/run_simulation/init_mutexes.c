/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutexes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:25:31 by bena              #+#    #+#             */
/*   Updated: 2023/06/24 19:50:07 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_mutexes.h"

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
	if (pthread_mutex_init(&stat->termination, NULL))
		pthread_mutex_destory(&stat->termination);
	else
		return (0);
	return (1);
}
